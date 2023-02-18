/*
 * arraypprint.h
 *
 *  Created on: Nov 29, 2015
 *      Author: steve
 */

#ifndef ARRAYPPRINT_H_
#define ARRAYPPRINT_H_

#include <string>
#include <sstream>   // Provides stringstream

#ifndef HIDEOUTPUT
#define HIDEOUTPUT 0 //NO OUTPUT
#endif


#if HIDEOUTPUT

#include <iostream>
#include <iomanip>

template <typename T>
int getPad(const T& item) {
	switch(sizeof(T)) {
	case 8:
		return 23;
	case 4:
		return 6;
	default:
		return 4;
	}
}

template <typename T, typename S>
void arraypprint(T ar[], S sz,S gap=0)
{

	if ( gap > 0 )
		std::cout << std::setw(4) << gap << "-gap [";
	else
		std::cout << std::setw(15) << " [";
	for(S i = 0; i < sz; ++i) {
		std::cout << std::setw(6) << ar[i];
	}
	std::cout << "]" << std::endl;
}

template <typename T, typename S>
void arraypprints(T ar[], S sz,std::string prestr,std::string poststr=std::string())
{
	std::cout << std::setw(9) << prestr << "[";
	for(S i = 0; i < sz; ++i) {
		std::cout << std::setw(getPad(ar[0])) << ar[i];
	}
	std::cout << "] " << poststr << std::endl;
}

template <typename T, typename S>
void array2pprints(T ar1[], S sz1,T ar2[], S sz2,std::string prestr=std::string(),std::string poststr=std::string())
{
	//std::stringstream sstm;
	std::cout << std::setw(9) << prestr << "[";
	for(S i = 0; i < sz1; ++i) {
		std::cout << std::setw(getPad(ar1[0])) << ar1[i];
	}
	std::cout << "][";

	for(S i = 0; i < sz2; ++i) {
		std::cout << std::setw(i==0 ? 4 : getPad(ar1[0])) << ar2[i];
	}
	std::cout << "] " << poststr << std::endl;
	//return sstm.str();
}



#else

template <typename T, typename S>
void arraypprint(T ar[], S sz,size_t gap=0)
{
	return;
}

template <typename T, typename S>
void arraypprints(T ar[], S sz,std::string prestr,std::string poststr=std::string()) {
	return;
}

template <typename T, typename S>
void array2pprints(T ar1[], S sz1,T ar2[], S sz2,std::string prestr=std::string(),std::string poststr=std::string())
{
	return;
}

#endif

template <typename T>
std::string numtostr(T n) {
	std::stringstream sstm;
	sstm << n;
	return sstm.str();
}


#endif /* ARRAYPPRINT_H_ */
