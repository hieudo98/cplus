#include <iostream>
#include "Fraction.h"
using namespace std;

// đã edit 1 lần 10:26
// hàm tối ưu phân số cho dễ nhìn.
void optimize(SPhanSo &ps)
{
	if (ps.mau < 0)
	{
		ps.mau = -ps.mau;
		ps.tu = -ps.tu;
	}
	int min = ps.tu;
	if (min<0) min = -min;
	if (min > ps.mau)
		min = ps.mau;
	for (int i = min; i >= 2; i--)
	{
		if (ps.tu%i == 0 && ps.mau%i == 0)
		{
			ps.tu /= i;
			ps.mau /= i;
			break;
		}
	}
}


//hàm toán tử xuất cout<<
ostream &operator << (ostream& os, SPhanSo PS)
{
	optimize(PS);
	if (PS.mau == 1 || PS.tu==0)
	{
		os << PS.tu;
	}
	else
		os << PS.tu << "/" << PS.mau;
	return os;
}

// hàm toán tử nhập cin>>
istream &operator >> (istream& is, SPhanSo& PS)
{
	is >> PS.tu >> PS.mau;
	return is;
}
//hàm ++ trước : ++i
SPhanSo operator ++(SPhanSo& PS)
{
	PS.tu = PS.tu + PS.mau;
	return PS;
}

// hàm ++ sau: i++
// có nghĩa là giá trị đươc trả về rồi mới cộng lên
// i=4 thì a=i++; a=4 và i=5

SPhanSo operator ++(SPhanSo& PS, int n)
{
	SPhanSo kq = PS;
	PS.tu = PS.tu + PS.mau;
	return kq;
}
// hàm -- trước xong mới trả về kq
SPhanSo operator --(SPhanSo& PS)
{
	PS.tu = PS.tu - PS.mau;
	return PS;
}

//hàm -- sau : trả về kq rồi --
SPhanSo operator --(SPhanSo& PS, int n)
{
	SPhanSo kq = PS;
	PS.tu = PS.tu - PS.mau;
	return kq;
}

// toán tử đảo dấu a=-a;

SPhanSo operator - (SPhanSo PS)
{
	PS.tu = -PS.tu;
	return PS;
}
// toán tử nghịch đảo a/b b/a
SPhanSo operator ~ (SPhanSo PS)
{
	int temp = PS.tu;
	PS.tu = PS.mau;
	PS.mau = temp;
	return PS;
}

// --------------------TOÁN TỬ TÍNH TOÁN-------------------------

// toán tử + : ps + ps, ps+ n, n+ ps
// ps+ ps
SPhanSo operator + (const SPhanSo &ps1, const SPhanSo &ps2)
{
	SPhanSo kq = { ps1.tu*ps2.mau + ps1.mau*ps2.tu, ps1.mau*ps2.mau };
	return kq;
}
// ps+ n
SPhanSo operator + (const SPhanSo &ps, const int &n)
{
	SPhanSo kq = ps;
	kq.tu += ps.mau*n;
	return kq;
}

// n+ ps
SPhanSo operator + (const int &n, const SPhanSo &ps)
{
	SPhanSo kq = ps;
	kq.tu += ps.mau*n;
	return kq;
}

// toán tử -
// ps1 - ps2
SPhanSo operator - (const SPhanSo &ps1, const SPhanSo &ps2)
{
	SPhanSo kq = { ps1.tu*ps2.mau - ps1.mau*ps2.tu, ps1.mau*ps2.mau };
	return kq;
}
// ps1 - n
SPhanSo operator - (const SPhanSo &ps, const int &n)
{
	SPhanSo kq = ps;
	kq.tu -= n*kq.mau;
	return kq;
}
// n - ps
SPhanSo operator - (const int &n, const SPhanSo &ps)
{
	SPhanSo kq = ps;
	kq.tu = n*kq.mau - kq.tu;
	return kq;
}

// toán tử *
// ps1 * ps2
SPhanSo operator * (const SPhanSo &ps1, const SPhanSo &ps2)
{
	SPhanSo kq = { ps1.tu*ps2.tu, ps1.mau*ps2.mau };
	return kq;
}
// ps * n
SPhanSo operator * (const SPhanSo &ps, const int &n)
{
	SPhanSo kq = ps;
	kq.tu *= n;
	return kq;
}
// n * ps
SPhanSo operator * (const int &n, const SPhanSo &ps)
{
	SPhanSo kq = ps;
	kq.tu *= n;
	return kq;
}


// toán tử /
// ps1 / ps2
SPhanSo operator / (const SPhanSo &ps1, const SPhanSo &ps2)
{
	SPhanSo kq = { ps1.tu*ps2.mau, ps1.mau*ps2.tu };
	return kq;
}
// ps / n
SPhanSo operator / (const SPhanSo &ps, const int &n)
{
	SPhanSo kq = ps;
	kq.mau *= n;
	return kq;
}
// n / ps
SPhanSo operator / (const int &n, const SPhanSo &ps)
{
	SPhanSo kq = ~ps;
	kq = n * kq;
	return kq;
}

// toán tử +=
// ps1 += ps2
void operator += (SPhanSo &ps1, const SPhanSo &ps2)
{
	ps1 = ps1 + ps2;
}
// ps += n
void operator += (SPhanSo &ps, const int &n)
{
	ps = ps + n;
}
// toán tử -=
//ps1 -= ps2;
void operator -= (SPhanSo &ps1, const SPhanSo &ps2)
{
	ps1 = ps1 - ps2;
}
// ps-=n
void operator -=(SPhanSo &ps, const int &n)
{
	ps = ps - n;
}
// toán tử *=
// ps1*=ps2;
void operator *= (SPhanSo &ps1, const SPhanSo &ps2)
{
	ps1 = ps1*ps2;
}
// ps*=n
void operator *=(SPhanSo &ps, const int &n)
{
	ps = ps*n;
}
//toán tử /=
// ps1/=ps2;
void operator /= (SPhanSo &ps1, const SPhanSo &ps2)
{
	ps1 = ps1 / ps2;
}
// ps*=n
void operator /=(SPhanSo &ps, const int &n)
{
	ps = ps / n;
}

// -------------------------TOÁN TỬ SO SÁNH------------------------

// toán tử so sánh trả về true or false
// toán tử >
// ps1 > ps2
bool operator > (const SPhanSo &ps1, const SPhanSo &ps2)
{
	if (ps1.tu*ps2.mau > ps1.mau*ps2.tu)
		return true;
	return false;
}
// ps > n
bool operator > (const SPhanSo &ps, const int &n)
{
	if (ps.tu > ps.mau*n)
		return true;
	return false;
}
// n> ps
bool operator > (const int &n, const SPhanSo &ps)
{
	if (n*ps.mau > ps.tu)
		return true;
	return false;
}
// toán tử >=
// ps1 >= ps2
bool operator >= (const SPhanSo &ps1, const SPhanSo &ps2)
{
	if (ps1.tu*ps2.mau >= ps1.mau*ps2.tu)
		return true;
	return false;
}
// ps >= n
bool operator >= (const SPhanSo &ps, const int &n)
{
	if (ps.tu >= ps.mau*n)
		return true;
	return false;
}
// n >= ps
bool operator >= (const int &n, const SPhanSo &ps)
{
	if (n*ps.mau >= ps.tu)
		return true;
	return false;
}
// toán tử <
// ps1 < ps2
bool operator < (const SPhanSo &ps1, const SPhanSo &ps2)
{
	if (ps1.tu*ps2.mau < ps1.mau*ps2.tu)
		return true;
	return false;
}
// ps < n
bool operator < (const SPhanSo &ps, const int &n)
{
	if (ps.tu < ps.mau*n)
		return true;
	return false;
}
// n < ps
bool operator < (const int &n, const SPhanSo &ps)
{
	if (n*ps.mau < ps.tu)
		return true;
	return false;
}
// toán tử <=
// ps1 <= ps2
bool operator <= (const SPhanSo &ps1, const SPhanSo &ps2)
{
	if (ps1.tu*ps2.mau <= ps1.mau*ps2.tu)
		return true;
	return false;
}
// ps <= n
bool operator <= (const SPhanSo &ps, const int &n)
{
	if (ps.tu <= ps.mau*n)
		return true;
	return false;
}
// n <= ps
bool operator <= (const int &n, const SPhanSo &ps)
{
	if (n*ps.mau <= ps.tu)
		return true;
	return false;
}
// toán tử ==
// ps1 == ps2
bool operator == (const SPhanSo &ps1, const SPhanSo &ps2)
{
	if (ps1.tu*ps2.mau == ps2.tu*ps1.mau)
		return true;
	return false;
}
// ps == n
bool operator == (const SPhanSo &ps, const int &n)
{
	if (ps.tu == n*ps.mau)
		return true;
	return false;
}
// n == ps
bool operator == (const int &n, const SPhanSo &ps)
{
	if (n*ps.mau == ps.tu)
		return true;
	return false;
}

// toán tử !=
// ps1 != ps2
bool operator != (const SPhanSo &ps1, const SPhanSo &ps2)
{
	if (ps1.tu*ps2.mau != ps2.tu*ps1.mau)
		return true;
	return false;
}
// ps != n
bool operator != (const SPhanSo &ps, const int &n)
{
	if (ps.tu != n*ps.mau)
		return true;
	return false;
}
// n != ps
bool operator != (const int &n, const SPhanSo &ps)
{
	if (n*ps.mau != ps.tu)
		return true;
	return false;
}
