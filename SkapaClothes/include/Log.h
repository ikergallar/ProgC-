#ifndef OBJECTS_LogsS_H_
#define OBJECTS_LogsS_H_

class Log
{
    private:
	    char* log [10];

    public:
	    Log(char*[]);
	    ~Log();

	    void insertarLog (char* Log);
	    void imprimirLog();
};
#endif /* OBJECTS_LogsS_H_ */
