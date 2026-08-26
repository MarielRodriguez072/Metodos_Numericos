
    FILE *fp;
    char ch;
    char filePath[PATH_MAX];
    snprintf(filePath, sizeof(filePath), "%s/../datos/matriz.dat", srcDir);
    fp = fopen(filePath,"r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo matriz.dat");
        return 1;
    }

    //contador de filas
    int filas=0;
    char c;
	int columnas;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen(filePath,"r");
    double m[filas][1000];


    //Cargo los datos leidos en el array
    int i, j;
	for(i = 0; i < filas; i++) {
		j = 0;
		do {
        fscanf(fp, "%lf", &(m[i][j]));
        j++;
			} while((c = fgetc(fp)) != '\n');
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA MATRIZ SON:\n");
    	
    for(i=0;i<filas;i++){
	    for(j=0;j<columnas;j++){
	        printf("%lf ",m[i][j]);
	    }
   		printf("\n");        
	}

    fclose(fp);

