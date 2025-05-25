#!/bin/bash
source config.sh

docker run --name ${CONTAINER_NAME} -v ${WORKING_DIR}:/home/jamespillot/scratch_space \
-it --rm ${IMAGE_NAME}:${VERSION}