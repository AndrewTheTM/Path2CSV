// Path2CSV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc!=3){
		cout << "Call this program with:" << endl << endl;
		cout << "Path2CSV input.pth output.csv" << endl;
	}

	char errMsg[256];
	void* path=PathReaderOpen(argv[1],errMsg,256);
	
	int prrn=1;
	PathRead_Data prd;
	prd.nodes=new int[PathReaderGetMaxPathLen(path)];
	prd.costs=new int[PathReaderGetMaxPathLen(path)];
	prd.vols=new float[PathReaderGetHighestVol(path)];
	int nPaths=PathReaderGetNumPaths(path);
	int countPaths=0;
	ofstream of;
	of.open(argv[2],iostream::trunc);
	while((prrn=PathReaderReadNext(path,&prd))>0){
		countPaths++;
		if(countPaths % 100) 
			of << prd.I << ",";
		for(int pn=0;pn<prrn;pn++){ 
			of << prd.nodes[pn];
			if(prd.nodes[pn]!=prd.J) 
				of <<",";
		}
		of << endl;
	}
	of.close();
	delete[] prd.nodes;
	delete[] prd.costs;
	delete[] prd.vols;

	return 0;
}

