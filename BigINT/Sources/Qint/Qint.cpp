#include "Header.h"
string DecToBin(int n)
{
	string a = "";
	bool LaSoAm = (n < 0);
	if (LaSoAm)
	{
		n = -n;
	}
	//chia lấy dư 
	while (n != 0)
	{
		a = char((n % 2) + 48) + a;
		n = n / 2;
	}
	int length = a.length();

	//thêm số 0 vào đầu chuổi cho đủ 32 bit
	for (int i = 31; i >= length; i--)
	{
		a = '0' + a;
	}
	if (LaSoAm) //nếu là số âm thì t đảo bit và + 1 vào 
	{
		//đảo bit
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '0')
				a[i] = '1';
			else
				a[i] = '0';
		}

		//cộng 1
		for (int i = a.length() - 1; i >= 0; i--)
		{
			if (a[i] == '1')
			{
				a[i] = '0';
			}
			else
			{
				a[i] = '1';
				break;
			}
		}
	}
	return a;
}
void QInt::SetBit(int vitri)
//vitri là vị trí của bit cần set thành 1 trong chuỗi 128 bit của mảng 4 số int 
//128 bit được chia làm 4 số int mỗi số 32 bit
//c sẽ cho biết bit cần set thuộc số nào trong 4 số a[0] a[1] a[2] a[3]
//b sẽ cho biết bit cần set thuộc bit nào trong 32bit của 1 số nguyên int  
{
	int c, b;
	c = vitri / 32;// vị trí 
	b = vitri % 32; // vị trí bit trong số nguyên 
	data[3 - c] = (data[3 - c] | (1 << b));
}


void QInt::NhapTuHe10(string a)
{
	int mod;
	int temp;
	string kq = "";
	bool LaSoAm = (a[0] == '-');
	if (LaSoAm) //a < 0
	{
		a.erase(a.begin());
		while (a != "0") // vòng while để chia cho đến khi chuối ban đầu về 0
		{
			mod = 0;
			for (int i = 0; i < a.length(); i++) // vòng for để thực hiện chia 2 số a ban đầu lấy được mod là số dư và cập nhật lại a/2
			{
				temp = (mod * 10 + (a[i] - 48)) / 2; // thực hiện phép chia cho 2 như cấp 1
				mod = (mod * 10 + (a[i] - 48)) % 2;
				a[i] = temp + 48;
			}
			//đảo bit thành số bù 1
			if (mod == 0)
				mod = 1;
			else
				mod = 0;
			//ghi vào chuỗi
			kq = char(mod + 48) + kq;
			if (a.length() > 1 && a[0] == '0') // xóa kí tự 0 k có nghĩa và để dừng vòng lặp while 
			{
				a.erase(a.begin());
			}
		}

		//+1 để thành số bù 2
		for (int i = kq.length() - 1; i >= 0; i--)
		{
			if (kq[i] == '1')
			{
				kq[i] = '0';
			}
			else
			{
				kq[i] = '1';
				break;
			}
		}
		//vì là số âm nên ta cần điền tất cả các bit đầu là bit 1
		int length = kq.length();
		for (int i = 127; i >= length; i--)
		{
			kq = '1' + kq;
		}
	}
	else // a > 0
	{
		while (a != "0")
		{
			mod = 0;
			for (int i = 0; i < a.length(); i++) // vòng for để thực hiện chia 2 số a ban đầu lấy được mod là số dư và cập nhật lại a/2
			{
				temp = (mod * 10 + (a[i] - 48)) / 2; // thực hiện phép chia cho 2 như cấp 1
				mod = (mod * 10 + (a[i] - 48)) % 2;
				a[i] = temp + 48;
			}
			kq = char(mod + 48) + kq;
			if (a.length() > 1 && a[0] == '0') // xóa kí tự 0 k có nghĩa và để dừng vòng lặp while 
			{
				a.erase(a.begin());
			}
		}
	}
	this->NhapTuHe2(kq);
}

void QInt::NhapTuHe2(string a)
{
	int Length = a.length();
	for (int i = Length - 1; i >= 0; i--)
	{
		if (a[i] == '1')
		{
			SetBit(Length - i - 1);
		}
	}
}

void QInt::NhapTuHe16(string a)
{
	//chuyển chuổi hệ 16 sang chuổi hệ 2
	string kq;
	for (int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case '0':
		{
					kq = kq + "0000";
					break;
		}
		case '1':
		{
					kq = kq + "0001";
					break;
		}
		case '2':
		{
					kq = kq + "0010";
					break;
		}
		case '3':
		{
					kq = kq + "0011";
					break;
		}
		case '4':
		{
					kq = kq + "0100";
					break;
		}
		case '5':
		{
					kq = kq + "0101";
					break;
		}
		case '6':
		{
					kq = kq + "0110";
					break;
		}
		case '7':
		{
					kq = kq + "0111";
					break;
		}
		case '8':
		{
					kq = kq + "1000";
					break;
		}
		case '9':
		{
					kq = kq + "1001";
					break;
		}
		case 'A':
		{
					kq = kq + "1010";
					break;
		}
		case 'B':
		{
					kq = kq + "1011";
					break;
		}
		case 'C':
		{
					kq = kq + "1100";
					break;
		}
		case 'D':
		{
					kq = kq + "1101";
					break;
		}
		case 'E':
		{
					kq = kq + "1110";
					break;
		}
		case 'F':
		{
					kq = kq + "1111";
					break;
		}
		}
	}

	//nhập Qint từ chuỗi hệ 2
	NhapTuHe2(kq);
}

string QInt::LayHe2()
{
	string kq = "";
	int i;
	//các data[i] = 0 ban đầu là 32 bit 0 không cần thiết, ta nên bỏ qua
	for (i = 0; i < 4; i++)
	{
		if (data[i] != 0)
			break;
	}
	// kể từ data[i] có giá trị != 0 đầu tiên, ta lấy từng 32 bit trong data
	for (i; i < 4; i++)
	{
		kq = kq + DecToBin(data[i]);
	}
	//xóa các số 0 không cần thiết 
	while (kq[0] == '0')
	{
		kq.erase(kq.begin());
	}
	
	return kq;
}
string QInt::LayHe10()
{
	string ChuoiNhiPhan, kq;
	ChuoiNhiPhan = LayHe2();
	kq = "0";
	int temp1; // dùng để lưu kết quả sau khi nhân 1 chữ số
	int check;
	//nếu là số âm thì phải đảo bit và trừ đi 1 trước khi tiến hành nhân 2 
	//sau đó thêm dấu trừ vào đầu chuổi kq
	bool LaSoAm = (data[0] < 0);
	if (LaSoAm)
	{
		//-1
		for (int i = ChuoiNhiPhan.length() - 1; i >= 0; i--)
		{
			if (ChuoiNhiPhan[i] == '0')
			{
				ChuoiNhiPhan[i] = '1';
			}
			else
			{
				ChuoiNhiPhan[i] = '0';
				break;
			}
		}
		//đảo bit
		for (int i = 0; i < ChuoiNhiPhan.length(); i++)
		{
			if (ChuoiNhiPhan[i] == '0')
				ChuoiNhiPhan[i] = '1';
			else
				ChuoiNhiPhan[i] = '0';
		}
		
		//xóa bit 0 vô nghĩa
		for (int i = 0; i < ChuoiNhiPhan.length(); i++)
		{
			if (ChuoiNhiPhan[i] == '0')
			{
				ChuoiNhiPhan.erase(ChuoiNhiPhan.begin());
			}
			else
				break;

		}
	}
	while (ChuoiNhiPhan != "")
	{
		if (ChuoiNhiPhan[0] == '1')
		{
			check = 1;
		}
		else
			check = 0;
		int temp2 = 0; // dùng để lưu " nhớ 1 "
		for (int i = kq.length() - 1; i >= 0; i--)
		{
			temp1 = (kq[i] - 48) * 2 + temp2; // kết quả sau khi nhân + phần nhớ của phép tính trên chữ số bên phải
			temp2 = 0;// sau khi cộng thì số nhớ phải là 0
			if (temp1 > 9)
			{
				temp1 = temp1 - 10;
				temp2 = 1; // nhớ 1
			}
			kq[i] = char(temp1 + 48);
			if (i == 0 && temp2 == 1)// phép tính còn dư 1 nhưng phía trước k còn phần tử nào để cộng thì cho 1 vào đầu
			{
				kq = "1" + kq;
			}
		}
		kq[kq.length() - 1] = char(((kq[kq.length() - 1] - 48) + check) + 48);
		ChuoiNhiPhan.erase(ChuoiNhiPhan.begin());
	}
	//ta thêm dấu trừ nếu là số âm
	if (LaSoAm)
		kq = '-' + kq;
	return kq;
}
string QInt::LayHe16()
{
	//lấy ra chuổi hệ 2
	string temp = LayHe2();

	//chuyển về chuổi hệ 16
	//vì ta dùng cách gộp 4 bit lại và quy đổi ra nên số bit cần là ước của 4,nếu số bit của chuổi 2 k phải là ước của 4
	//ta cần thêm các bbit 0 vào cho đủ
	string kq, compare;
	int temp1;
	temp1 = temp.length() % 4;
	if (temp1 != 0)
	{
		for (int i = 4-temp1; i >0; i--)
		{
			temp = '0' + temp;
		}
	}
	int len = temp.length();
	for (int i = 0; i < len / 4; i++)
	{
		compare = temp.substr(0, 4);
		if (compare == "0000")
		{
			kq = kq + '0';
		}
		else
		if (compare == "0001")
		{
			kq = kq + '1';
		}
		else
		if (compare == "0010")
		{
			kq = kq + '2';
		}
		else
		if (compare == "0011")
		{
			kq = kq + '3';
		}
		else
		if (compare == "0100")
		{
			kq = kq + '4';
		}
		else
		if (compare == "0101")
		{
			kq = kq + '5';
		}
		else
		if (compare == "0110")
		{
			kq = kq + '6';
		}
		else
		if (compare == "0111")
		{
			kq = kq + '7';
		}
		else
		if (compare == "1000")
		{
			kq = kq + '8';
		}
		else
		if (compare == "1001")
		{
			kq = kq + '9';
		}
		else
		if (compare == "1010")
		{
			kq = kq + 'A';
		}
		else
		if (compare == "1011")
		{
			kq = kq + 'B';
		}
		else
		if (compare == "1100")
		{
			kq = kq + 'C';
		}
		else
		if (compare == "1101")
		{
			kq = kq + 'D';
		}
		else
		if (compare == "1110")
		{
			kq = kq + 'E';
		}
		else
		{
			kq = kq + 'F';
		}
		temp.erase(0, 4);
	}
	return kq;
}

//toán tử AND, OR, XOR, NOT
QInt QInt::operator+(QInt b){
	string a, c;
	a = this->LayHe2();
	c = b.LayHe2();
	//thêm 0 vào chuỗi để hai chuỗi có length bằng nhau
	if (a.length() > c.length()){
		int n = a.length() - c.length();
		for (int i = 0; i < n; i++){
			c = "0" + c;
		}
	}
	else {
		int n = c.length() - a.length();
		for (int i = 0; i < n; i++){
			a = "0" + a;
		}
	}
	a = '0' + a;
	c = '0' + c;
	//cộng bit từ cuối chuỗi lên đầu chuỗi
	int k = 0;
	for (int i = a.length() - 1; i >= 0; i--){
		int t = a[i] - 48 + c[i] - 48 + k;
		if (t == 0 || t == 1){
			a[i] = t + 48;
			k = 0;
		}
		//nếu bit 1 + 1 thì bằng 0 là nhớ 1
		else if (t == 2){
			a[i] = '0';
			k = 1;
		}
		//nếu bit 1 + 1 + (nhớ 1 của 2 số trước) thì bit = 1 và nhớ 1
		else if (t == 3){
			a[i] = '1';
			k = 1;
		}
	}

	while (a.length() > 128){
		a = a.substr(1, a.length() - 1);
	}
	while (a[0] - 48 == 0){
		a = a.substr(1, a.length() - 1);
	}
	
	
	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::operator -(QInt b)
{
	string a, temp;
	a = this->LayHe2();
	temp = b.LayHe2();
	//thêm đủ 128bit để trừ 2 số
	for (int i = a.length() - 1; i < 128; i++){
		a = "0" + a;
	}
	for (int i = temp.length() - 1; i < 128; i++){
		temp = "0" + temp;
	}
	//trừ bit từ cuối chuỗi lên đầu chuỗi
	int k = 0;
	for (int i = a.length() - 1; i >= 0; i--){
		int c = (a[i] - 48) - (temp[i] - 48) - k;
		if (c == 0 || c == 1){
			a[i] = c + 48;
			k = 0;
		}
		//nếu bit 0 - 1 - (nhớ 1 của 2 số trước) thì bit = 0 và nhớ 1
		else if (c == -2){
			a[i] = '0';
			k = 1;
		}
		//nếu bit 0 - 1 thì bit = 1 và nhớ 1
		else if (c == -1){
			a[i] = '1';
			k = 1;
		}
	}
	if (a.length() > 128)
	{
		a = a.substr(1, a.length() - 1);
	}
	if (a[0] - 48 == 0){
		a = a.substr(1, a.length() - 1);
	}
	if (a.length() == 0)
	{
		for (int i = 0; i < 128; i++)
		{
			a[i] = '0';
		}
	}

	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}
//hàm cộng 2 chuỗi
string cong(string a, string b){
	a = "0" + a;
	b = "0" + b;
	if (a.length() > b.length()){
		int n = a.length() - b.length();
		for (int i = 0; i < n; i++){
			b = "0" + b;
		}
	}
	else {
		int n = b.length() - a.length();
		for (int i = 0; i < n; i++){
			a = "0" + a;
		}
	}

	int k = 0;
	for (int i = a.length() - 1; i >= 0; i--){
		int c = a[i] - 48 + b[i] - 48 + k;
		if (c == 0 || c == 1){
			a[i] = c + 48;
			k = 0;
		}
		else if (c == 2){
			a[i] = '0';
			k = 1;
		}
		else if (c == 3){
			a[i] = '1';
			k = 1;
		}
	}
	if (a.length() > 128){
		a = a.substr(1, a.length() - 1);
	}
	while (a[0] - 48 == 0){
		a = a.substr(1, a.length() - 1);
	}
	if (a.length() == 0){
		for (int i = 0; i < 128; i++){
			a = a + "0";
		}
	}
	return a;
}
//hàm nhân 2 chuỗi
string nhan(string a, string b){
	string c;
	for (int i = b.length() - 1; i >= 0; i--){
		if (b[i] - 48 == 1){
			c = cong(c, a);
		}
		a = a + "0";
	}
	return c;
}


QInt QInt::operator *(QInt b)
{
	string a, temp, kq, z;
	QInt x , y;
	a = this->LayHe10();
	temp = b.LayHe10();
	//trường hợp cả 2 số đều âm
	if (this->data[0] < 0 && b.data[0] < 0){
		//xóa dấu
		a = a.erase(0, 1);
		temp = temp.erase(0, 1);
		//cập nhật lại số
		x.NhapTuHe10(a);
		y.NhapTuHe10(temp);
		//nhân 2 số
		a = x.LayHe2();
		temp = y.LayHe2();
		kq = nhan(a, temp);
		QInt k;
		k.NhapTuHe2(kq);
		z = k.LayHe10();
	}
	//trường hợp 1 số âm và 1 số dương
	else if (this->data[0] < 0 && b.data[0] >= 0){
		//xóa dấu số âm
		a = a.erase(0, 1);
		//cập nhật lại số âm
		x.NhapTuHe10(a);
		y.NhapTuHe10(temp);
		//nhân 2 số
		a = x.LayHe2();
		temp = y.LayHe2();
		kq = nhan(a, temp);
		//thêm dấu vào kết quả
		QInt k;
		k.NhapTuHe2(kq);
		z = k.LayHe10();
		z = "-" + z;
	}
	else if (this->data[0] >= 0 && b.data[0] < 0){//tương tự như trên
		temp = temp.erase(0, 1);
		x.NhapTuHe10(a);
		y.NhapTuHe10(temp);
		a = x.LayHe2();
		temp = y.LayHe2();
		kq = nhan(a, temp);
		QInt k;
		k.NhapTuHe2(kq);
		z = k.LayHe10();
		z = "-" + z;
	}
	//trường hợp 2 số đều dương
	else {
		a = this->LayHe2();
		temp = b.LayHe2();
		kq = nhan(a, temp);
		QInt k;
		k.NhapTuHe2(kq);
		z = k.LayHe10();
	}
	QInt c;
	c.NhapTuHe10(z);
	return c;
}

int SoSanhTrenChuoi10(string a, string b)
{
	int lena, lenb;
	lena = a.length();
	lenb = b.length();
	if (lena > lenb)
	{
		return 1;
	}
	else
	if (lenb > lena)
	{
		return -1;
	}
	else//lena==lenb;
	{
		for (int i = 0; i < lena; i++)
		{
			if (a[i] > b[i])
			{
				return 1;
			}
			else
			if (a[i] < b[i])
			{
				return -1;
			}
		}
		return 0;
	}

}

string Sub(string a, string b)
//trừ 2 số hệ 10 a - b với a chắc chắn lớn hơn b
//nếu a < b thì trả về "-1"
{
	string kq = "";
	if (SoSanhTrenChuoi10(a, b) == -1)//a<b
	{
		kq = "-1";
		return kq;
	}
	//thêm số 0 vào đầu chuổi b cho bằng độ dài với chuổi a
	while (b.length() < a.length())
	{
		b = '0' + b;
	}
	//tiến hành trừ từng chữ số
	int temp, extra = 0;
	//temp để lưu giá trị vừa trừ được, extra dùng để lưu xem có nợ khi trừ ở bước trước không
	for (int i = a.length() - 1; i >= 0; i--)
	{
		temp = (a[i] - 48) - (b[i] - 48) - extra;
		extra = 0;
		if (temp < 0)
		{
			temp = temp + 10;
			extra = 1;
		}
		kq = char(temp + 48) + kq;
	}
	while (kq[0] == '0' &&kq.length() != 1)
	{
		kq.erase(kq.begin());
	}
	return kq;
}

QInt QInt::operator/(QInt b)
{
	QInt KetQua;
	string SoChia, SoBiChia, KetQuaS = "0", temp1, temp2, extra;
	int temp3 = 0;
	//KetQuaS là kết quả sau khi chia ở dạng chuỗi 10
	//temp1 là chuôi cắt ra để thực hiện phép chia
	//temp2 dùng lưu kết quả sau mỗi lần trừ
	//temp3 kết quả sau 1 lần chia
	//extra phần dư sau 1 phép chia 
	SoBiChia = this->LayHe10();
	SoChia = b.LayHe10();
	bool SoBiChiaLaSoAm = (SoBiChia[0] == '-');
	bool SoChiaLaSoAm = (SoChia[0] == '-');
	// nếu là số âm thì xóa dấu trừ rồi sau đó ta chia trên số dương rồi xét lại dấu sau
	if (SoChiaLaSoAm)
	{
		SoChia.erase(SoChia.begin());
	}
	if (SoBiChiaLaSoAm)
	{
		SoBiChia.erase(SoBiChia.begin());
	}

	//chia
	if (SoSanhTrenChuoi10(SoBiChia, SoChia) == -1) // số bị chia nhỏ hơn số chia
	{
		KetQuaS = "0";
		return KetQua;
		//kết quả = 0 thì k cần set lại bit nên cứ giữ nguyên KetQua
	}
	while (SoBiChia != "")
	{
		//temp1 = SoBiChia.substr(0, DoDaiSoChia);
		temp1 = extra + SoBiChia[0];
		SoBiChia.erase(SoBiChia.begin());
		while (true) // vòng while này lấy số temp1 đã đc cắt ra - cho số chia đến khi nào temp1 < SoChia
			//sau mỗi lần trừ được thì temp3 tăng lên 1
			//kết thúc vòng while ta sẽ được temp3 là kết quả chia và extra là phần dư, sau đó lại hạ các số sau xuống và chia tiếp
		{
			temp2 = Sub(temp1, SoChia);

			if (temp2 == "-1")
			{
				extra = temp1;
				break;
			}
			else
			{
				temp3++;
				temp1 = temp2;
			}
		}
		KetQuaS = KetQuaS + char(temp3 + 48);
		temp3 = 0;
	}
	if ((SoBiChiaLaSoAm && !SoChiaLaSoAm) || (!SoBiChiaLaSoAm &&SoChiaLaSoAm))
	{
		KetQuaS = '-' + KetQuaS;
	}
	KetQua.NhapTuHe10(KetQuaS);
	return KetQua;
}

QInt QInt::operator&(QInt b)
{
	string a, c;
	a = LayHe2();
	c = b.LayHe2();
	if (a.length() > c.length()){
		int n = a.length() - c.length();
		for (int i = 0; i < n; i++){
			c = "0" + c;
		}
	}
	else {
		int n = c.length() - a.length();
		for (int i = 0; i < n; i++){
			a = "0" + a;
		}
	}
	//cùng bit 1 thì bằng 1 , ngược lại thì bằng 0
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == c[i] && a[i] == '1')
		{
			a[i] = '1';
		}
		else
			a[i] = '0';
	}
	
	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::operator|(QInt b)
{
	string a, c;
	a = LayHe2();
	c = b.LayHe2();
	//thêm 0 vào để 2 chuỗi có length bằng nhau
	if (a.length() > c.length()){
		int n = a.length() - c.length();
		for (int i = 0; i < n; i++){
			c = "0" + c;
		}
	}
	else {
		int n = c.length() - a.length();
		for (int i = 0; i < n; i++){
			a = "0" + a;
		}
	}
	//cùng bit 0 thì bằng 0, ngược lại thì bằng 1
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == c[i] && a[i] == '0')
		{
			a[i] = '0';
		}
		else
			a[i] = '1';
	}

	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::operator^(QInt b)
{
	string a, c;
	a = LayHe2();
	c = b.LayHe2();
	if (a.length() > c.length()){
		int n = a.length() - c.length();
		for (int i = 0; i < n; i++){
			c = "0" + c;
		}
	}
	else {
		int n = c.length() - a.length();
		for (int i = 0; i < n; i++){
			a = "0" + a;
		}
	}
	//cùng bit thì bằng 0 ngược lại thì bằng 1
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == c[i])
		{
			a[i] = '0';
		}
		else
			a[i] = '1';
	}

	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::operator~()
{
	string a;
	a = this->LayHe2();
	//nếu bit 0 thì bật thành bit 1
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '1')
		{
			a[i] = '0';
		}
		else
			a[i] = '1';
	}
	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::operator>>(int k)
{
	string a;
	a = this->LayHe2();
	//trường hợp là số đầu tiên là 1 thì ta phải thêm k lần số 1 sau khi dịch
	if (a.length() == 128 && a[0] == '1')
	{
		a.erase(a.length() - k, k);
		for (int i = 0; i < k; i++)
		{
			a = "1" + a;
		}
	}
	else
	{
		a.erase(a.length() - k, k);
		for (int i = 0; i < k; i++)
		{
			a = "0" + a;
		}
	}
	
	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::operator<<(int k)
{
	string a;
	a = this->LayHe2();
	a.erase(0, k);
	//dịch và thêm 0 vào cuối
	for (int i = 0; i < k; i++)
	{
		a = a + "0";
	}

	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::ror(int k)
{
	string a;
	a = this->LayHe2();
	if (a[a.length() - 1] == '0')
	{
		a = "0" + a;
	}
	else
	{
		a = "1" + a;
	}
	a.erase(a.length() - 1, 1);
	
	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}

QInt QInt::rol(int k)
{
	string a;
	a = this->LayHe2();
	if (a[0] == '0')
	{
		a = a + "0";
	}
	else
	{
		a = a + "1";
	}
	a.erase(0, 1);

	QInt kq;
	kq.NhapTuHe2(a);
	return kq;
}
