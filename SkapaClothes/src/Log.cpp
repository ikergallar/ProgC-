/*
#include "Log.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

Log::Log(char* logsR[10])
{
	logs=logsR;
}

void Log::insertarLog(char* log)
{
	int lleno=1;
	for(int i=0; i<10;i++)
    {
        if(logs[i]=="")
        {
			logs[i]==log;
			lleno=0;
			break;
		}
	}
	if(lleno==1)
	{
		logs[9]=log;
	}
}

void Log::imprimirLog (){
	for(int i=0; i<10;i++){
		if(logs[i]!=""){
			cout<<"Log "<<i<<": "<<logs[i];
		}else{
			break;
		}

		}
}
*/
