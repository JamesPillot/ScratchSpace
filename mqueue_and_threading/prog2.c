#include <fcntl.h>           /* For O_* constants */
#include <mqueue.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>        /* For mode constants */

#define MAX_MSGS 5; // 5 messages
#define MAX_MSG_SIZE 16; // 16 bytes
/*This side receives messages*/
int main()
{
    /*Name of mqueue we open*/
    char* const mq1_name = "/MQ1";
    /*Flags for mqueue*/
    int mq1_flag = O_RDONLY;
    /*Mode for mqueue creation*/
    mode_t mq1_mode = 0660;
    /*Attribute struct*/
    struct mq_attr mq1_attr;
    mq1_attr.mq_maxmsg = MAX_MSGS;
    mq1_attr.mq_msgsize = MAX_MSG_SIZE;
    /*Open mqueue*/
    mqd_t mq1_des = mq_open(mq1_name, mq1_flag, mq1_mode, &mq1_attr);
    if (mq1_des == -1)
    {
        printf("%s failed to open\n", mq1_name);
        exit(1);
    }
    /*Receive message*/
    #pragma pack(push, 1)
    typedef struct {
        uint32_t first;
        uint32_t second;
        uint32_t third;
        uint32_t fourth;
    } msg_body_t;
    #pragma pop

    msg_body_t mq1_msg;

    int rcv_res = mq_receive(mq1_des, (char*)(&mq1_msg), sizeof(mq1_msg), 0);
    if (rcv_res == -1)
    {
        printf("Failed to recieve message from %s\n", mq1_name);
        exit(1);
    }
    else
    {
        printf("First byte of message is %x\n", mq1_msg.first);
    }
    /*Close mqueue*/
    int close_res = mq_close(mq1_des);
    if (close_res == -1)
    {
        printf("%s failed to close\n", mq1_name);
        exit(1);
    }
    return 0;
}