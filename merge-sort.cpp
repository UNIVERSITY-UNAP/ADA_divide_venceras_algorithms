int Merge(int B[],int const p,int const q,int const r){
	
	int N1 = q - p +1;
	int N2 = r-q;
	  
	int *L = new int();
	int *R = new int();
	
	
	for(int i=0; i<N1; i++){
	    *(L+i)=B[p+i-1]; 
	}
	for(int j=0; j<N2; j++){
	    *(R+j)=B[q+j]; 
	}
	
	int cont1 = 0;
	int cont2 = 0;
	int M = p-1;
	
	for(int k=p-1; k<r-1; k++){
	    if(L[cont1] <= R[cont2]){
	      B[k] = L[cont1];
	      cont1++;
	    }
	    else{
	      B[k] = R[cont2];
	      cont2++;
	    }
	    M++;
	}
	

	while (cont1 < N1) {
		B[M] = L[cont1];
		cont1++;
		M++;
	}

	while (cont2 < N2) {
		B[M] = R[cont2];
		cont2++;
		M++;
	}
}
	
int MergeSort(int B[],int p,int r){
	if(p < r){
	    int q = (p + r)/2;
	    MergeSort(B,p,q);
	    MergeSort(B,q+1,r);
	    Merge(B,p,q,r);
	}
}