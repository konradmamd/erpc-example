INCLUDE1 = ./erpc/erpc_c/setup/
INCLUDE2 = ./erpc/erpc_c/infra/
INCLUDE3 = ./erpc/erpc_c/port/
INCLUDE4 = ./erpc/erpc_c/config/
INCLUDE5 = ./erpc/erpc_c/transports/
LIBRARY1 = ./erpc/Debug/Linux/erpc/lib/

all:
	${CXX} client.c erpc_matrix_multiply_client.cpp -I${INCLUDE1} -I${INCLUDE2} -I${INCLUDE3} -I${INCLUDE4} -I${INCLUDE5} -L${LIBRARY1} -lerpc -lpthread -std=gnu++0x -o client
	${CXX} server.c erpc_matrix_multiply_server.cpp -I${INCLUDE1} -I${INCLUDE2} -I${INCLUDE3} -I${INCLUDE4} -I${INCLUDE5} -L${LIBRARY1} -lerpc -lpthread -std=gnu++0x -o server

