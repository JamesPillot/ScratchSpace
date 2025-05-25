#!/bin/bash
source config.sh

docker run --name rust_dev_env -v ${WORKING_DIR}:/home/jamespillot/learning_rust -it --rm ${IMAGE_NAME}:${VERSION}