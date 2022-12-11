#include <stdio.h>
#include <stdlib.h>
#define ENTER_CHAR 13
#define NEW_LINE_CHAR 10

int _Length(char *string, char k) // hàm đếm số lượng kí tự trong chuỗi
{
	int length = 0;
	while ((int)*string != (int)k) // lặp cho đến khi gặp kí tự ngắt chuỗi
	{
		length++;
		string++;
	}
	return length; // trả về độ dài của chuỗi
}
int _Number_check(char _cChar)
{
	switch (_cChar)
	{
	case '3':
		return 1;
		break;
	case '1':
		return 1;
		break;
	case '8':
		return 1;
		break;
	case '7':
		return 1;
		break;
	case '6':
		return 1;
		break;
	case '(':
		return 1;
		break;
	case 'n':
		return 1;
		break;
	default:
		return 0;
	}
}
int _Behind_X_Check(char _cChar)
{
	switch (_cChar)
	{
	case 'd':
		return 1;
		break;
	case 'n':
		return 1;
		break;
	case 'm':
		return 1;
		break;
	case 't':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}
int _check(char *_sString_1, char *_sString_2)
{
	int check = 0;
	int _nLength = _Length(_sString_1, 10);
	for (int i = 0; i < _nLength; i++)
	{
		if (_Behind_X_Check(*(_sString_1 + i)) == 1)
		{
			int j = i;
			char _aRes_String[256];
			int _nCount_of_Res = 0;
			// printf("%c    %c \n", _sString_1[i], _sString_2[i]);
			while (*(_sString_2 + j) != ',' && *(_sString_2 + j) != 10 && *(_sString_2 + j) != '[' && *(_sString_2 + j) != ']')
			{
				_aRes_String[_nCount_of_Res] = *(_sString_2 + j);
				j++;
				_nCount_of_Res++;
				// printf("%c          ", _aRes_String[_nCount_of_Res - 1]);
			}
			for (int k = 0; k < _nCount_of_Res; k++)
			{
				if (_aRes_String[k] < '0' || _aRes_String[k] > '9')
				{
					return 0;
				}
			}
			if (*(_sString_2 + i + 1) != ',' && *(_sString_2 + i + 1) != '\n' && *(_sString_2 + i + 1) != '[' && *(_sString_2 + i + 1) != ']')
			{
				int k = i;
				while (*(_sString_2 + k) != 10)
				{
					*(_sString_2 + k) = *(_sString_2 + k + 1);
					k++;
				}
				i--;
			}
		}
		else if (_Number_check(*(_sString_1 + i)) == 1) // phần này là kiểm tra số xem nó nằm đúng trong khoảng chưa
		{
			int j = i;
			char _aRes_String[256];
			int _nCount_of_Res = 0;
			while (*(_sString_2 + j) != ',' && *(_sString_2 + j) != 10 && *(_sString_2 + j) != '[' && *(_sString_2 + j) != ']')
			{
				_aRes_String[_nCount_of_Res] = *(_sString_2 + j);
				j++;
				_nCount_of_Res++;
			}
			for (int k = 0; k < _nCount_of_Res; k++)
			{
				if (k == 0 && (_aRes_String[k] == '-' || (_aRes_String[k] >= '0' && _aRes_String[k] <= '9')))
				{
					continue;
				}
				else if (_aRes_String[k] == '-' || _aRes_String[k] < '0' || _aRes_String[k] > '9')
				{
					return 0;
				}
			}
			// phần này sẽ để check xem có đúng trong khoảng không:) ai biết làm như nào
			unsigned long long _Num_Res = 0;
			for (int k = 0; k < _nCount_of_Res; k++)
			{
				_Num_Res = _Num_Res * 10 + _aRes_String[k];
			}
			switch (_sString_1[i])
			{
			case '3':
				if (_Num_Res > 4096)
					return 0;
				return 1;
			case '1':
				if (_Num_Res < -262143 || _Num_Res > 262143)
					return 0;
				return 1;
			case '8':
				if (_Num_Res < 0 || _Num_Res > 65535)
					return 0;
				return 1;
			case '7':
				if (_Num_Res < -262143 || _Num_Res > 262143)
					return 0;
				return 1;
				break;
			case '6':
				if (_Num_Res > 63 || _Num_Res < 0)
					return 0;
				return 1;
				break;
			case '(':
				if (_Num_Res < -265 || _Num_Res > 255)
					return 0;
				return 1;
				break;
			case 'n':
				if (_Num_Res < 0 || _Num_Res > 65535)
					return 0;
				return 1;
			default:
				printf("Loi phan mem");
				break;
			}
			if (*(_sString_2 + i + 1) != ',' && *(_sString_2 + i + 1) != '\n' && *(_sString_2 + i + 1) != '[' && *(_sString_2 + i + 1) != ']')
			{
				int k = i;
				while (*(_sString_2 + k) != 10)
				{
					*(_sString_2 + k) = *(_sString_2 + k + 1);
					k++;
				}
				i--;
			}
		}
		else
		{
			if (*(_sString_1 + i) != *(_sString_2 + i))
				return 0;
		}
	}
	return 1;
}
void _ChuanHoa(char **string) // hàm chuẩn hóa toàn bộ dữ liệu đầu vào, tuy nhiên phải viết lại toàn bộ do với trường họp a dd sẽ bị sai
{
	// hàm này sẽ xóa bỏ các dấu cách thừa ở đầu hàng
	while (*string[0] == ' ')
	{
		*string = (*string + 1);
	}
	int _nLength_to_Space = _Length(*string, ' ');
	int _nLength_to_End = _Length(*string, 10);
	// hàm này in hoa toàn bộ chữ cái đầu hàng
	for (int i = 0; i < _nLength_to_Space; i++)
	{
		if (*(*string + i) >= 'a' && *(*string + i) <= 'z')
		{
			*(*string + i) -= 32;
		}
	}
	for (int i = _nLength_to_Space + 1; i < _nLength_to_End; i++)
	{
		if (*(*string + i) == ' ')
		{
			int res = i;
			while (*(*string + res) != 10)
			{
				*(*string + res) = *(*string + res + 1);
				res++;
			}
			_nLength_to_End--;
			i--;
		}
	}
	_nLength_to_Space = _Length(*string, ' ');
	_nLength_to_End = _Length(*string, 10);
	for (int i = _nLength_to_Space - 1; i < _nLength_to_End; i++)
	{
		if (*(*string + i) == 'x')
		{
			*(*string + i) -= 32;
		}
	}
}
int main()
{
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	// All datasheet
	//-------A----Start-----///
	/*
	 start with A:
		 ADD Xd,Xn,Xm
		 ADDS Xd,Xn,Xm
		 ADDI Xd,Xn,#
		 ADDIS Xd,Xn,#
		 AND Xd,Xn,Xm
		 ANDI Xd,Xn,#

	 */
	char ADD[] = "ADD Xd,Xn,Xm\n";
	char ADDS[] = "ADDS Xd,Xn,Xm\n";
	char ADDI[] = "ADDI Xd,Xn,3\n";
	char ADDIS[] = "ADDIS Xd,Xn,3\n";
	char AND[] = "AND Xd,Xn,Xm\n";
	char ANDI[] = "ANDI Xd,Xn,3\n";
	//-------B----Start-----///
	/*
 start with B:
	 B #simm26
	 BR Xt
	 BL #simm26
	 B.cond #simm19
	 B.EQ
	 B.NE
	 B.LT
	 B.LE
	 B.GT
	 B.GE
	 B.MI
	 B.VS
	 B.LS
	 B.LO
	 B.HI
	 B.HS
	 B.PL
 */
	char B[] = "B 8\n";
	char BR[] = "BR Xt\n";
	char BL[] = "BL 8\n";
	char BCOND[] = "B.COND 1\n";
	char BEQ[] = "B.EQ 8\n";
	char BNE[] = "B.NE 8\n";
	char BLT[] = "B.LT 8\n";
	char BLE[] = "B.LE 8\n";
	char BGT[] = "B.GT 8\n";
	char BGE[] = "B.GE 8\n";
	char BMI[] = "B.MI 8\n";
	char BVS[] = "B.VS 8\n";
	char BLS[] = "B.LS 8\n";
	char BLO[] = "B.LO 8\n";
	char BHI[] = "B.HI 8\n";
	char BHS[] = "B.HS 8\n";
	char BPL[] = "B.PL 8\n";
	//-------C----Start-----///
	/*
		 start with C:
			 C
			 CBZ Xt
			 CBNZ Xt
			 CMP Xn, Xm
			 CMPI Xn, #uimm12
		 */
	char CBZ[] = "CBZ Xt\n";
	char CBNZ[] = "CBNZ Xt\n";
	char CMP[] = "CMP Xn,Xm\n";
	char CMPI[] = "CMPI XN,3\n";
	//-------E----Start-----//
	/*
		EOR Xd, Xn, Xm/#uimm12
	*/
	char EOR_1[] = "EOR Xd,Xn,Xm\n";
	char EOR_2[] = "EOR Xd,Xn,3\n";
	//-------L----Start-----//
	/*
	start with L:
		LDUR Xt, [Xn,#simm9]
		LDURSW Xt, [Xn,#simm9]
		LDURH Xt, [Xn,#simm9]
		LDURB Xt, [Xn,#simm9]
		LSL Xd, Xn, #uimm6
		LSR Xd, Xn, #unimm6
	*/
	char LDUR[] = "LDUR Xt,[Xn,(]\n";
	char LDURSW[] = "LDUR Xt,[Xn,(]\n";
	char LDURH[] = "LDURH Xt,[Xn,(]\n";
	char LDURB[] = "LDURB Xt,[Xn,(]\n";
	char LSL[] = "LSL Xd,Xn,6\n";
	char LSR[] = "LSR Xd,Xn,6\n";
	//-------M----Start-----//
	/*
	start with M:
		MOV Xd, Xn
		MOVZ Xd, #uimm12, LSL N
		MOVK Xd, #uimm16, LSL N
	*/
	char MOV[] = "MOV Xd,Xn\n";
	char MOVZ[] = "MOVZ Xd,3,LSLn\n"; // cấn chỗ này nghen:))))))) xem trên slack
	char MOVK[] = "MOVK Xd,3,LSLn\n";
	//-------O----Start-----//
	/*
	start with O:
		ORR Xd, Xn, Xm
		ORRI Xd, Xn, #uimm12
	*/
	char ORR[] = "ORR Xd,Xn,Xm\n";
	char ORRI[] = "ORRI Xd,Xn,3\n";
	//-------S----Start-----//
	/*
	start with S:
		SUB Xd, Xn, Xm
		SUBS Xd, Xn, Xm
		SUBI Xd, Xn, #uimm12
		SUBIS Xd, Xn, Xm
		STUR Xt, [Xn, #simm9]
		STURW Xt, [Xn, #simm9]
		STURH Xt, [Xn, #simm9]
		STURB Xt, [Xn, #simm9]

	*/
	char SUB[] = "SUB Xd,Xn,Xm\n";
	char SUBS[] = "SUBS Xd,Xn,Xm\n";
	char SUBI[] = "SUBI Xd,Xn,3\n";
	char SUBIS[] = "SUBIS Xd,Xn,Xm\n";
	char STUR[] = "STUR Xt,[Xn,(]\n";
	char STURW[] = "STURW Xt,[Xn,(]\n";
	char STURH[] = "STURH Xt,[Xn,(]\n";
	char STURB[] = "STURB Xt,[Xn,(]\n";
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

	FILE *datafld;
	datafld = fopen("data.txt", "r"); // mở file
	if (datafld == NULL)
	{
		printf("\nFile is unable to open"); // nếu mở file không thành công, báo lỗi và exit
		exit(0);
	}
	char **line_data = NULL;
	line_data = (char **)malloc(100 * sizeof(char *));
	line_data[0] = (char *)malloc(100 * sizeof(char));
	int row = 0;
	int col = 0;
	while (!feof(datafld)) // truyền dữ liệu vào mảng động 2 chiều
	{
		char res = 10;
		fscanf(datafld, "%c", &res);
		line_data[row][col] = res;
		col++;
		if (res == ENTER_CHAR || res == NEW_LINE_CHAR)
		{
			row++;
			//	printf("%d\n", col);
			line_data[row] = (char *)malloc(100 * sizeof(char));
			col = 0;
		}
	}
	for (int i = 0; i < row; i++)
	{ // chuẩn hóa lại dữ liệu đầu vào: xóa khoảng trắng đầu hàng, in hoa chữ cái
		_ChuanHoa(&line_data[i]);
	}
	// trường hợp dữ liệu đầo vào sai khoảng cách như A   DD hoặc, X   2
	//.main.loop
	int check_num = 0;
	for (int i = 0; i < row; i++)
	{
		switch (line_data[i][0])
		{
		case 'A':
			int _nRes_A = 0;
			_nRes_A += _check(ADD, line_data[i]);
			_nRes_A += _check(ADDS, line_data[i]);
			_nRes_A += _check(ADDI, line_data[i]);
			_nRes_A += _check(ADDIS, line_data[i]);
			_nRes_A += _check(AND, line_data[i]);
			_nRes_A += _check(ANDI, line_data[i]);
			if (_nRes_A == 1)
			{
				check_num += _nRes_A;
				break;
			}
			else
				goto Wrong_Answer;
		case 'B':
			int _nRes_B = 0;
			_nRes_B += _check(B, line_data[i]);
			_nRes_B += _check(BR, line_data[i]);
			_nRes_B += _check(BL, line_data[i]);
			_nRes_B += _check(BCOND, line_data[i]);
			_nRes_B += _check(BEQ, line_data[i]);
			_nRes_B += _check(BNE, line_data[i]);
			_nRes_B += _check(BLT, line_data[i]);
			_nRes_B += _check(BLE, line_data[i]);
			_nRes_B += _check(BGT, line_data[i]);
			_nRes_B += _check(BGE, line_data[i]);
			_nRes_B += _check(BMI, line_data[i]);
			_nRes_B += _check(BVS, line_data[i]);
			_nRes_B += _check(BLS, line_data[i]);
			_nRes_B += _check(BLO, line_data[i]);
			_nRes_B += _check(BHI, line_data[i]);
			_nRes_B += _check(BHS, line_data[i]);
			_nRes_B += _check(BPL, line_data[i]);
			if (_nRes_B == 1)
			{
				check_num += _nRes_B;
				break;
			}
			else
				goto Wrong_Answer;
		case 'C':
			int _nRes_C = 0;
			_nRes_C += _check(CBZ, line_data[i]);
			_nRes_C += _check(CBNZ, line_data[i]);
			_nRes_C += _check(CMP, line_data[i]);
			_nRes_C += _check(CMPI, line_data[i]);
			if (_nRes_C == 1)
			{
				check_num += _nRes_C;
				break;
			}
			else
				goto Wrong_Answer;
		case 'E':
			int _nRes_E = 0;
			_nRes_E += _check(EOR_1, line_data[i]);
			_nRes_E += _check(EOR_2, line_data[i]);
			if (_nRes_E == 1)
			{
				check_num += _nRes_E;
				break;
			}
			else
				goto Wrong_Answer;
		case 'L':
			int _nRes_L = 0;
			_nRes_L = _check(LDUR, line_data[i]);
			_nRes_L = _check(LDURSW, line_data[i]);
			_nRes_L = _check(LDURH, line_data[i]);
			_nRes_L = _check(LDURB, line_data[i]);
			_nRes_L = _check(LSL, line_data[i]);
			_nRes_L = _check(LSR, line_data[i]);
			if (_nRes_L == 1)
			{
				check_num += _nRes_L;
				break;
			}
			else
				goto Wrong_Answer;
		case 'M':
			int _nRes_M = 0;
			_nRes_M += _check(MOV, line_data[i]);
			_nRes_M += _check(MOVZ, line_data[i]);
			_nRes_M += _check(MOVK, line_data[i]);
			if (_nRes_M == 1)
			{
				check_num += _nRes_M;
				break;
			}
			else
				goto Wrong_Answer;
		case 'O':
			int _nRes_O = 0;
			_nRes_O += _check(ORR, line_data[i]);
			_nRes_O += _check(ORRI, line_data[i]);
			if (_nRes_O == 1)
			{
				check_num += _nRes_O;
				break;
			}
			else
				goto Wrong_Answer;
		case 'S':
			int _nRes_S = 0;
			_nRes_S += _check(SUB, line_data[i]);
			_nRes_S += _check(SUBS, line_data[i]);
			_nRes_S += _check(SUBI, line_data[i]);
			_nRes_S += _check(SUBIS, line_data[i]);
			_nRes_S += _check(STUR, line_data[i]);
			_nRes_S += _check(STURW, line_data[i]);
			_nRes_S += _check(STURH, line_data[i]);
			_nRes_S += _check(STURB, line_data[i]);
			if (_nRes_S == 1)
			{
				check_num += _nRes_S;
				break;
			}
			else
				goto Wrong_Answer;
		case '.':
			int j = 0;
			while (line_data[i][j] != 10 && line_data[i][j] != 13)
			{
				if (line_data[i][j] == ' ' || line_data[i][j] == '!' || line_data[i][j] == '[' || line_data[i][j] == ']' || line_data[i][j] == '(' || line_data[i][j] == ')' || line_data[i][j] == '{' || line_data[i][j] == '}' || line_data[i][j] == '&' || line_data[i][j] == '*' || line_data[i][j] == '#' || line_data[i][j] == '%' || line_data[i][j] == '^' || line_data[i][j] == '@' || line_data[i][j] == '$')
					goto Wrong_Answer;
				j++;
			}
			check_num += 1;
			break;
		default:
			check_num += 0;
			break;
		}
	}
	if (check_num == row)
	{
		printf("all line pass");
	}
	else
	{
	Wrong_Answer:
		printf("one or more lines are false");
	}
	for (int i = 0; i < row - 1; i++) // xóa cấp phát mảng động 2 chiều
	{
		free(line_data[i]);
	}
	free(line_data);
	fclose(datafld); // đóng file
	return (0);
}
