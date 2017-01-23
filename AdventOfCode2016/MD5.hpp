//-----------------------------------------------------------------------------
// Standard RFC1321 MD5 checksum algorithm
//
// Ported from code at http://www.fourmilab.ch/md5/
// The license for the code states:
// This software is in the public domain. Permission to use, copy, modify, and
// distribute this software and its documentation for any purpose and without
// fee is hereby granted, without any conditions or restrictions. This
// software is provided "as is" without express or implied warranty.
//-----------------------------------------------------------------------------

#ifndef INCL_MD5_H
#define INCL_MD5_H

#include <sys/types.h>
#include <string>

typedef unsigned int uint32;

struct MD5Context
{
	uint32        buf[4];
	uint32        bits[2];
	unsigned char in[64];
};

//-----------------------------------------------------------------------------
class MD5
{
public:
	// Default constructor
	MD5();

	// Destructor
	~MD5();

	// Returns a string which is the hex representation of the MD5
	// digest of the message.
	std::string          getMD5(const void* buf, int buflen);

	// Checksum a file without reading the whole thing into memory at one time.
	// Returns empty string on error.
	std::string          checksumFile(const char* filename);

	// Returns a pointer to a 16-character binary buffer which is the MD5
	// digest of the message.
	const unsigned char* getDigest(const void* buf, int buflen);

private:
	void                 MD5Init(MD5Context* ctx);
	void                 MD5Update(MD5Context* ctx, const unsigned char* buf, unsigned len);
	void                 MD5Final(unsigned char digest[16], MD5Context* ctx);
	void                 MD5Transform(uint32 buf[4], uint32 in[16]);
	void                 byteReverse(unsigned char* buf, unsigned longs);

	// Variables
	unsigned char        signature[16];
};

#endif