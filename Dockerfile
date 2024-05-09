#The image to be loaded/downloaded
FROM ubuntu:22.04

#Updating package lists
RUN apt-get update -y

#Installing libraries
RUN apt-get install -y build-essential g++ libstdc++6 cmake gdb

#Add extra libraries to install here
# RUN apt-get install -y valgrind

#Setting the work directory in the container
WORKDIR /multiply_two_bytes/

#Copying your files here
COPY . /multiply_two_bytes/

# Set the default command to run when the container starts
CMD ["/bin/bash"]








