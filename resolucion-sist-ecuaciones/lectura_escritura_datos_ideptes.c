
    FILE *fd;

    char dataDirInd[PATH_MAX];
    strncpy(dataDirInd, __FILE__, sizeof(dataDirInd));
    dataDirInd[sizeof(dataDirInd)-1] = '\0';
    dirname(dataDirInd);

    char filePathInd[PATH_MAX];
    snprintf(filePathInd, sizeof(filePathInd), "%s/datos/matrizIndep.dat", dataDirInd);
    fd = fopen(filePathInd,"r");
    if ( fd == NULL )
    {
        puts ( "No se puede abrir el archivo matrizIndep.dat");
        return 1;
    }

    //Cargo los datos leidos en el array
	for(int i = 0; i < filas; i++) {
		do {
        fscanf(fd, "%lf", &(b[i]));
			} while((c = fgetc(fd)) != '\n');
	}

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS TERMINOS INDEPENDIENTES DE LA MATRIZ SON:\n");
    	
    for(int i=0;i<filas;i++){
	        printf("%lf ",b[i]);
   		printf("\n");        
	}

    fclose(fd);

