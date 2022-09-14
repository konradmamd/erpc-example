#include <stdio.h>
#include "erpc_matrix_multiply_server.h"  // auto-generated by erpcgen
#include "erpc_matrix_multiply.h"         // auto-generated by erpcgen
#include "erpc_server_setup.h"            // from erpc source

/* implementation of function call */
void erpcMatrixMultiply(Matrix matrix1, Matrix matrix2, Matrix result_matrix)
{
    int32_t i, j, k;
    
    printf("Received call to erpcMatrixMultiply... ");

    /* Clear the result matrix */
    for (i = 0; i < matrix_size; ++i)
    {
        for (j = 0; j < matrix_size; ++j)
        {
            result_matrix[i][j] = 0;
        }
    }

    /* Multiply two matrices */
    for (i = 0; i < matrix_size; ++i)
    {
        for (j = 0; j < matrix_size; ++j)
        {
            for (k = 0; k < matrix_size; ++k)
            {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    printf("Done.\n");
}

int main()
{
    printf("Initializing... ");
    
    /* Init eRPC server environment */
    /* TCP transport layer initialization */
    erpc_transport_t transport = erpc_transport_tcp_init("127.0.0.1", 5407, true);

    /* MessageBufferFactory initialization */
    erpc_mbf_t message_buffer_factory = erpc_mbf_dynamic_init();

    /* eRPC server side initialization */
    erpc_server_init(transport, message_buffer_factory);

    /* connect generated service into server, look into erpc_matrix_multiply_server.h */
    erpc_service_t service = create_MatrixMultiplyService_service();
    erpc_add_service_to_server(service);
    
    printf("Done.\nWaiting for request...\n");

    /* run server */
    erpc_server_run(); /* or erpc_server_poll(); */

    return 0;
}
