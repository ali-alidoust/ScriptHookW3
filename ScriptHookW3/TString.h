#pragma once

#define DECLARE_CONSTRUCTOR(name, sig) \
name ## sig; \
typedef name* (*__constructor_type) ## sig; \
__constructor_type __constructor ## sig;

#define DEFINE_CONSTRUCTOR(fullname, sig) \
fullname ## sig { __constructor ## sig; } \
fullname ## :: ## __constructor_type = nullptr;



class TString
{
public:
	// DECLARE_CONSTRUCTOR(TString, (void));
	TString();
	~TString();
};

