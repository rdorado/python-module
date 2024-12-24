FROM alpine:latest

# Set the working directory in the container
WORKDIR /app

# Create directory for the binaries output
COPY src/module /app/bin

# Install necessary dependencies
RUN apk update && apk upgrade && apk add \
    g++ \
    cmake \
	make \
    python3 \
    python3-dev \
	py3-pip

# Copy the source code into the container
COPY src/main.py /app

# Build the module
RUN cd /app/bin; python setup.py build

# Install the module
RUN cd /app/bin; \
    pip3 install --break-system-packages -e .

# Run the test to load the compiled library
CMD ["python3", "./main.py"]