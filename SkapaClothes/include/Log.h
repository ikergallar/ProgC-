#ifndef OBJECTS_LogsS_H_
#define OBJECTS_LogsS_H_

class Log {

private:
	static string Log [10];
public:
	Log(string[]);
	~Log();				//DESTRUCTOR
	void insertarLog (string Log);
	void imprimirLog();
};

#endif /* OBJECTS_LogsS_H_ */
