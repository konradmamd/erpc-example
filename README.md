Matrix multiplication example using eRPC and a server/client written in C, over a TCP transport.

## Getting Started

The following are instructions on building the code on a CentOS 7.9 machine (both the client and server are built for the host).

1. Install required packages.

    ```
    $ sudo yum install bison flex boost-devel
    ```

2. Setup Python 3.

    Python 3 is required to build eRPC. This is arleady installed by default on CentOS, however, the `python` binary still points to Python 2. We can work around this by using the alternatives command. This step can be skipped if using the latest eRPC version as the `python3` binary is automatically located and used.

    ```
    # Start by registering python2 as an alternative
    $ sudo alternatives --install /usr/bin/python python /usr/bin/python2 50

    # Register python3.5 as an alternative
    $ sudo alternatives --install /usr/bin/python python /usr/bin/python3.5 60

    # Select which Python version to use
    $ sudo alternatives --config python
    ```

3. Clone repo and build eRPC.

    ```
	$ git clone --recurse-submodules https://github.com/konradmamd/erpc-example.git
	$ cd erpc-example/erpc && make
	$ cd ..
	```

4. Generate shim code and build example.

    ```
	$ erpc/Debug/Linux/erpcgen/erpcgen erpc_matrix_multiply.erpc
	$ make
    ```

Your directory should look something like this;

```
$ ls -1a
.
..
client
client.c
erpc
erpc_matrix_multiply_client.cpp
erpc_matrix_multiply.erpc
erpc_matrix_multiply.h
erpc_matrix_multiply_server.cpp
erpc_matrix_multiply_server.h
.git
.gitignore
.gitmodules
Makefile
README.md
server
server.c
```

You can now run the server and client binaries and see output on the console.

## Resources
* https://community.nxp.com/t5/MCUXpresso-SDK-Knowledge-Base/Introducing-eRPC/ta-p/1099139
* https://github.com/EmbeddedRPC/erpc-imx-demos
* https://github.com/EmbeddedRPC/erpc/wiki/Getting-Started
* https://programmersought.com/article/88827920353/
* https://programmersought.com/article/37585084512/

