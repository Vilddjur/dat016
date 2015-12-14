; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/oskarje/u117.c"

;     1 | void main(void)
;	locals:
;		'a' at 3,SP (Value: -2,SP)
;		'b' at 1,SP (Value: -4,SP)
;		'c' at 0,SP (Value: -5,SP)

;	No registers allocated

	SEGMENT	text
	EXPORT	_main	[r,2]
_main:

;     2 | {
	LEAS	-5,SP
;     3 | int a;
;     4 | short int b;
;     5 | char c;
;     6 | 
;     7 | a=1;
	LDD	#1
	STD	3,SP
;     8 | b=2;
	LDD	#2
	STD	1,SP
;     9 | c=3;
	LDAB	#3
	STAB	0,SP
;    10 | }
	LEAS	5,SP
	RTS
