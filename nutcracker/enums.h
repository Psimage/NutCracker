#pragma once

#define SQOBJECT_REF_COUNTED	0x08000000
#define SQOBJECT_NUMERIC		0x04000000
#define SQOBJECT_DELEGABLE		0x02000000
#define SQOBJECT_CANBEFALSE		0x01000000

// #define _RT_MASK 0x00FFFFFF
// #define _RAW_TYPE(type) (type&_RT_MASK)

#define _RT_NULL			0x00000001
#define _RT_INTEGER			0x00000002
#define _RT_FLOAT			0x00000004
#define _RT_BOOL			0x00000008
#define _RT_STRING			0x00000010
#define _RT_TABLE			0x00000020
#define _RT_ARRAY			0x00000040
#define _RT_USERDATA		0x00000080
#define _RT_CLOSURE			0x00000100
#define _RT_NATIVECLOSURE	0x00000200
#define _RT_GENERATOR		0x00000400
#define _RT_USERPOINTER		0x00000800
#define _RT_THREAD			0x00001000
#define _RT_FUNCPROTO		0x00002000
#define _RT_CLASS			0x00004000
#define _RT_INSTANCE		0x00008000
#define _RT_WEAKREF			0x00010000
#define _RT_OUTER			0x00020000

enum SQObjectType : int
{
	OT_NULL = (_RT_NULL | SQOBJECT_CANBEFALSE),
	OT_INTEGER = (_RT_INTEGER | SQOBJECT_NUMERIC | SQOBJECT_CANBEFALSE),
	OT_FLOAT = (_RT_FLOAT | SQOBJECT_NUMERIC | SQOBJECT_CANBEFALSE),
	OT_BOOL = (_RT_BOOL | SQOBJECT_CANBEFALSE),
	OT_STRING = (_RT_STRING | SQOBJECT_REF_COUNTED),
	OT_TABLE = (_RT_TABLE | SQOBJECT_REF_COUNTED | SQOBJECT_DELEGABLE),
	OT_ARRAY = (_RT_ARRAY | SQOBJECT_REF_COUNTED),
	OT_USERDATA = (_RT_USERDATA | SQOBJECT_REF_COUNTED | SQOBJECT_DELEGABLE),
	OT_CLOSURE = (_RT_CLOSURE | SQOBJECT_REF_COUNTED),
	OT_NATIVECLOSURE = (_RT_NATIVECLOSURE | SQOBJECT_REF_COUNTED),
	OT_GENERATOR = (_RT_GENERATOR | SQOBJECT_REF_COUNTED),
	OT_USERPOINTER = _RT_USERPOINTER,
	OT_THREAD = (_RT_THREAD | SQOBJECT_REF_COUNTED),
	OT_FUNCPROTO = (_RT_FUNCPROTO | SQOBJECT_REF_COUNTED), //internal usage only
	OT_CLASS = (_RT_CLASS | SQOBJECT_REF_COUNTED),
	OT_INSTANCE = (_RT_INSTANCE | SQOBJECT_REF_COUNTED | SQOBJECT_DELEGABLE),
	OT_WEAKREF = (_RT_WEAKREF | SQOBJECT_REF_COUNTED),
	OT_OUTER = (_RT_OUTER | SQOBJECT_REF_COUNTED) //internal usage only
};

enum Opcode : unsigned char
{
	OP_LINE = 0x00,
	OP_LOAD = 0x01,
	OP_LOADINT = 0x02,
	OP_LOADFLOAT = 0x03,
	OP_DLOAD = 0x04,
	OP_TAILCALL = 0x05,
	OP_CALL = 0x06,
	OP_PREPCALL = 0x07,
	OP_PREPCALLK = 0x08,
	OP_GETK = 0x09,
	OP_MOVE = 0x0A,
	OP_NEWSLOT = 0x0B,
	OP_DELETE = 0x0C,
	OP_SET = 0x0D,
	OP_GET = 0x0E,
	OP_EQ = 0x0F,
	OP_NE = 0x10,
	OP_ADD = 0x11,
	OP_SUB = 0x12,
	OP_MUL = 0x13,
	OP_DIV = 0x14,
	OP_MOD = 0x15,
	OP_BITW = 0x16,
	OP_RETURN = 0x17,
	OP_LOADNULLS = 0x18,
	OP_LOADROOT = 0x19,
	OP_LOADBOOL = 0x1A,
	OP_DMOVE = 0x1B,
	OP_JMP = 0x1C,
	//OP_JNZ=				0x1D,
	OP_JCMP = 0x1D,
	OP_JZ = 0x1E,
	OP_SETOUTER = 0x1F,
	OP_GETOUTER = 0x20,
	OP_NEWOBJ = 0x21,
	OP_APPENDARRAY = 0x22,
	OP_COMPARITH = 0x23,
	OP_INC = 0x24,
	OP_INCL = 0x25,
	OP_PINC = 0x26,
	OP_PINCL = 0x27,
	OP_CMP = 0x28,
	OP_EXISTS = 0x29,
	OP_INSTANCEOF = 0x2A,
	OP_AND = 0x2B,
	OP_OR = 0x2C,
	OP_NEG = 0x2D,
	OP_NOT = 0x2E,
	OP_BWNOT = 0x2F,
	OP_CLOSURE = 0x30,
	OP_YIELD = 0x31,
	OP_RESUME = 0x32,
	OP_FOREACH = 0x33,
	OP_POSTFOREACH = 0x34,
	OP_CLONE = 0x35,
	OP_TYPEOF = 0x36,
	OP_PUSHTRAP = 0x37,
	OP_POPTRAP = 0x38,
	OP_THROW = 0x39,
	OP_NEWSLOTA = 0x3A,
	OP_GETBASE = 0x3B,
	OP_CLOSE = 0x3C,
};

enum BitWiseOpcode
{
	BW_AND = 0,
	BW_OR = 2,
	BW_XOR = 3,
	BW_SHIFTL = 4,
	BW_SHIFTR = 5,
	BW_USHIFTR = 6
};

enum ComparisionOpcode
{
	CMP_G = 0,
	CMP_GE = 2,
	CMP_L = 3,
	CMP_LE = 4
};

enum AppendArrayType {
	AAT_STACK = 0,
	AAT_LITERAL = 1,
	AAT_INT = 2,
	AAT_FLOAT = 3,
	AAT_BOOL = 4
};
