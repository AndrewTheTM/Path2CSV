// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#ifndef __VOYAGERFILEACCESS_H__
#define __VOYAGERFILEACCESS_H__

#ifdef VOYAGER_EXPORT
#define EXP __declspec(dllexport)
#else
#define EXP __declspec(dllimport)
#endif

typedef struct
{
	int	*nodes;	// Node buffer for path reader to fill
	int	*costs;	// Cost buffer for path reader to fill
	float	*vols;	// Volume buffer for path reader to fill
	int	numNodes;	// Number of nodes in path
	int	numCosts;	// Number of costs in path
	int	highestVol;	// Highest vol number in path
	int	iteration;	// Iteration of path read
	int	I;	// I of path read
	int	J;	// J of path read
	int	table;	// Table of path read
} PathRead_Data;


#ifdef __cplusplus
extern "C"{
#endif
	EXP void* PathReaderOpen(const char *filename, char *errMsg, int errBufLen);
	EXP void PathReaderClose(void *state);
	EXP int PathReaderReadDirect(void *state, int iter, int i, int tab, int j,PathRead_Data *returnData);
	EXP void PathReaderRewind(void *state);
	EXP int PathReaderReadNext(void *state, PathRead_Data *returnData);
	EXP int PathReaderGetTableNames(void* state, char **names);
	EXP int PathReaderGetNumZones(void *state);
	EXP int PathReaderGetNumTables(void *state);
	EXP int PathReaderGetNumIterations(void *state);
	EXP int PathReaderGetHighestVol(void *state);
	EXP int PathReaderGetMaxPathLen(void *state);
	EXP int PathReaderGetNumPaths(void *state);

#ifdef __cplusplus
}
#endif
#endif


// TODO: reference additional headers your program requires here
