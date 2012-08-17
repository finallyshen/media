

#define LOG 				printf
#define MAX_BUFFER_SIZE 		50 

struct media_base
{
	/*
	 * API function: set configure data, some data need to notify
	 * 
	 * */
	int (* set_config)( int,void * );

	/*
	 * API functio: get some data have been set
	 * */
	int (* get_config)( int,void * );
	/*
	 * API function: give buffer
	 * 
	 * */
	int (* set_input_data)( int,void * );
	/*
	 * API function: get buffer
	 *
	 * */
	int (* get_output_data)( int,void * );
	/*
	 * Local Function add buffer to buffer queue
	 *
	 * */
	int (* add_buffer)( void );
	/*
	 * Local Function remove buffer of buffer queue
	 *
	 * */
	int (* remove_buffer)( void );

	/*
	 * Local buffer queue for add data 
	 *
	 * */
	void * in_buffer[MAX_BUFFER_SIZE];
	/*
	 * Local buffer queue for out data
	 * 
	 * */
	void * out_buffer[MAX_BUFFER_SIZE];

	/*
	 * Local thread to make buffer 
	 *
	 * */
	void * buffer_proc( void * );
}

