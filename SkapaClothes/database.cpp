BaseDeDatos::BaseDeDatos(char *nomBD) {
	this->nomBD = new char[strlen(nomBD)+1];
    strcpy(this->nomBD, nomBD);
}

BaseDeDatos::~BaseDeDatos() {
    delete[] nomBD;
}

//Método para abrir la base de datos_:
void BaseDeDatos::abrirBD(){
    if(sqlite3_open(nomBD,&db)!=SQLITE_OK)
    {
        cout<<"Error al intentar abrir la base de datos"<<endl;
    }
}

//Método para cerrar la base de datos_:
void BaseDeDatos::cerrarBD(){
    if(sqlite3_close(db)!=SQLITE_OK)
    {
        cout<<"Error al intentar cerrar la base de datos"<<endl;
    }
}

//Método para insertar nuevo vuelo en la base de datos_:
void BaseDeDatos::insertarNuevoVuelo(const Vuelo &v){
	char query[100];
	int resul = existeVuelo(v.getNumV());
	if(resul==1)
        cout<<"ERROR! El número de vuelo insertado ya está registrado"<<endl;
    else{
        sprintf(query,"INSERT INTO Vuelos (numV,origen,destino) VALUES (%d,'%s','%s')",v.getNumV(),v.getOrigen(),v.getDestino());
        if(sqlite3_prepare_v2(db,query,strlen(query)+1,&stmt,NULL)!=SQLITE_OK)
        {
            cout<<"Error sqlite_prepare_v2"<<endl;
        }else{
           sqlite3_step(stmt);
           sqlite3_finalize(stmt);
        }
    }

}
