#include <iostream>
#include <cstdlib>
#include <cmath>
#include<string.h>


using namespace std;

/* Constants for MD5Transform routine. */
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21


#define MAXNUM 65536
/* F, G, H and I are basic MD5 functions.
*/
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits.
*/
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
Rotation is separate from addition to prevent recomputation.
*/
#define FF(a, b, c, d, x, s, ac) { \
	(a) += F ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
	(a) += G ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
	(a) += H ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
	(a) += I ((b), (c), (d)) + (x) + ac; \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
}


int main()
{
	while(1){
		//set ABCD
		unsigned long A = 0x67452301;
		unsigned long B = 0xefcdab89;
		unsigned long C = 0x98badcfe;
		unsigned long D = 0x10325476;
		//abcd  use to calculate
		unsigned long a;
		unsigned long b;
		unsigned long c;
		unsigned long d;
		unsigned long num = 0;
		unsigned long M[16];
		char info[MAXNUM] = "\0";
	
		printf("Please enter a string(Ctrl + C to exit): ");
		gets(info);
		num = strlen(info);
	
		//string length less than 2^64
		__int64 strLength = num * 8;
		int addCount = 0;
		//calculate append number(byte)
		for(addCount = 0; addCount < 64; addCount++){
			if((num + addCount) % 64 == 56){
				break;
			}			
		}
		//append 1 and addCount 0
		for (int i = 0; i < addCount; i++){
			if(i == 0){
				info[num++] = (char)0x80;
			}else {
				info[num++] = 0;
			}
		}	
		//append string length 
		memmove(info + num, (char*) &strLength, sizeof(strLength));
		//64 bits length of the string
		num += 8;
	
	
		for( int i = 0; i < num; i += 64)
		{
			a = A;
			b = B;
			c = C;
			d = D;
			memmove((char*)M,info+i,64);
			//Round1
			FF(a, b, c, d, M[0], 7, 0xd76aa478);
			FF(d, a, b, c, M[1], 12, 0xe8c7b756);
			FF(c, d, a, b, M[2], 17, 0x242070db);
			FF(b, c, d, a, M[3], 22, 0xc1bdceee);
			FF(a, b, c, d, M[4], 7, 0xf57c0faf);
			FF(d, a, b, c, M[5], 12, 0x4787c62a);
			FF(c, d, a, b, M[6], 17, 0xa8304613);
			FF(b, c, d, a, M[7], 22, 0xfd469501);
			FF(a, b, c, d, M[8], 7, 0x698098d8);
			FF(d, a, b, c, M[9], 12, 0x8b44f7af);
			FF(c, d, a, b, M[10], 17, 0xffff5bb1);
			FF(b, c, d, a, M[11], 22, 0x895cd7be);
			FF(a, b, c, d, M[12], 7, 0x6b901122);
			FF(d, a, b, c, M[13], 12, 0xfd987193);
			FF(c, d, a, b, M[14], 17, 0xa679438e);
			FF(b, c, d, a, M[15], 22, 0x49b40821);
			//Round2
			GG(a, b, c, d, M[1], 5, 0xf61e2562);
			GG(d, a, b, c, M[6], 9, 0xc040b340);
			GG(c, d, a, b, M[11], 14, 0x265e5a51);
			GG(b, c, d, a, M[0], 20, 0xe9b6c7aa);
			GG(a, b, c, d, M[5], 5, 0xd62f105d);
			GG(d, a, b, c, M[10], 9, 0x02441453);
			GG(c, d, a, b, M[15], 14, 0xd8a1e681);
			GG(b, c, d, a, M[4], 20, 0xe7d3fbc8);
			GG(a, b, c, d, M[9], 5, 0x21e1cde6);
			GG(d, a, b, c, M[14], 9, 0xc33707d6);
			GG(c, d, a, b, M[3], 14, 0xf4d50d87);
			GG(b, c, d, a, M[8], 20, 0x455a14ed);
			GG(a, b, c, d, M[13], 5, 0xa9e3e905);
			GG(d, a, b, c, M[2], 9, 0xfcefa3f8);
			GG(c, d, a, b, M[7], 14, 0x676f02d9);
			GG(b, c, d, a, M[12], 20, 0x8d2a4c8a);
			//Round3
			HH(a, b, c, d, M[5], 4, 0xfffa3942);
			HH(d, a, b, c, M[8], 11, 0x8771f681);
			HH(c, d, a, b, M[11], 16, 0x6d9d6122);
			HH(b, c, d, a, M[14], 23, 0xfde5380c);
			HH(a, b, c, d, M[1], 4, 0xa4beea44);
			HH(d, a, b, c, M[4], 11, 0x4bdecfa9);
			HH(c, d, a, b, M[7], 16, 0xf6bb4b60);
			HH(b, c, d, a, M[10], 23, 0xbebfbc70);
			HH(a, b, c, d, M[13], 4, 0x289b7ec6);
			HH(d, a, b, c, M[0], 11, 0xeaa127fa);
			HH(c, d, a, b, M[3], 16, 0xd4ef3085);
			HH(b, c, d, a, M[6], 23, 0x04881d05);
			HH(a, b, c, d, M[9], 4, 0xd9d4d039);
			HH(d, a, b, c, M[12], 11, 0xe6db99e5);
			HH(c, d, a, b, M[15], 16, 0x1fa27cf8);
			HH(b, c, d, a, M[2], 23, 0xc4ac5665);
			//Round4
			II(a, b, c, d, M[0], 6, 0xf4292244);
			II(d, a, b, c, M[7], 10, 0x432aff97);
			II(c, d, a, b, M[14], 15, 0xab9423a7);
			II(b, c, d, a, M[5], 21, 0xfc93a039);
			II(a, b, c, d, M[12], 6, 0x655b59c3);
			II(d, a, b, c, M[3], 10, 0x8f0ccc92);
			II(c, d, a, b, M[10], 15, 0xffeff47d);
			II(b, c, d, a, M[1], 21, 0x85845dd1);
			II(a, b, c, d, M[8], 6, 0x6fa87e4f);
			II(d, a, b, c, M[15], 10, 0xfe2ce6e0);
			II(c, d, a, b, M[6], 15, 0xa3014314);
			II(b, c, d, a, M[13], 21, 0x4e0811a1);
			II(a, b, c, d, M[4], 6, 0xf7537e82);
			II(d, a, b, c, M[11], 10, 0xbd3af235);
			II(c, d, a, b, M[2], 15, 0x2ad7d2bb);
			II(b, c, d, a, M[9], 21, 0xeb86d391);
			A += a;
			B += b;
			C += c;
			D += d;
		}	
		//convert to hex
		unsigned char r[16];
		memmove(r+0,(char *)&A,4);
		memmove(r+4,(char *)&B,4);
		memmove(r+8,(char *)&C,4);
		memmove(r+12,(char *)&D,4);
		printf("MD5 : \n");
		for(int i = 0; i < 16; i++){
			printf("%02x",r[i]);
		}		
		printf("\n");
		
	}	
	return 0;
}


