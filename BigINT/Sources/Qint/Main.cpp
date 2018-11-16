#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS

int demKhoangTrang(string s){                   // Đếm khoảng trắng, nếu = 2 thì ta có các phép toán: 1.Chuyển cơ số
	int dem = 0;                                //                                                    2.Toán tử NOT
	for (int i = 0; i < s.length(); i++){      //                                                    3.Phép xoay
		if (s[i] == ' ')                        //                   nếu = 3 thì ta có các phép toán: 1.Toán hạng(+,-,*,/)
			dem++;                              //                                                    2.Phép dịch
	}                                           //                                                    3.Toán tử AND,OR,XOR
	return dem;
}

char* chuyenStringSangChar(string a){
	char* p;
	p = new char[a.length() + 1];
	strcpy(p, a.c_str());
	return p;
}

vector <char*> tachChuoi(char* p){
	vector <char*> res;
	char* temp = strtok(p, " ");
	while (temp != 0){
		res.push_back(temp);
		temp = strtok(NULL, " ");
	}
	return res;
}

int main(int argc, char* argv[])
{
	/*QInt a, b;
	a.NhapTuHe16("85AF");
	b.NhapTuHe16("90BC");
	a = a + b;
	string c = a.LayHe16();
	cout << c << endl;*/


    string a;
    fstream f, fo;
	char* p;

    f.open("input.txt",ios::in);
	fo.open("output.txt", ios::out);
    while(!f.eof()){
        getline(f,a);
        if (demKhoangTrang(a) == 3)
        {
			QInt x, y;
            p = chuyenStringSangChar(a);
            vector<char*> res;
            res = tachChuoi(p);
            if (*res[0] == '2')     //Kiểm tra hệ cơ số -> TH này làm trên cơ số 2
            {
                if (*res[2] == '+'){     //Kiểm tra phép toán -> TH này là phép +
                // hàm + cơ số 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x + y;
					fo << x.LayHe2() << endl;
                }
                else if (*res[2] == '-'){
                    // hàm - cơ số 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x - y;
					fo << x.LayHe2() << endl;
                }
                else if (*res[2] == '*'){
                    // hàm * cơ số 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x * y;
					fo << x.LayHe2() << endl;
                }
                else if (*res[2] == '/'){
                    // hàm / cơ số 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x / y;
					fo << x.LayHe2() << endl;
                }
                else if (strcmp(res[2],">>") == 0){
                    // hàm dịch phải
					x.NhapTuHe2((string)res[1]);
					int k = atoi(res[3]);
					x = x >> k;
					fo << x.LayHe2() << endl;
                }
                else if (strcmp(res[2],"<<") == 0){
                    // hàm dịch trái
					x.NhapTuHe2((string)res[1]);
					int k = atoi(res[3]);
					x = x << k;
					fo << x.LayHe2() << endl;
                }
                else if (strcmp(res[2],"&") == 0){
                    // ham AND 2 so he 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x & y;
					fo << x.LayHe2() << endl;
                }
                else if (strcmp(res[2],"|") == 0){
                    // ham OR 2 so he 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x | y;
					fo << x.LayHe2() << endl;
                }
                else if (strcmp(res[2],"^") == 0){
                    // ham XOR 2 so he 2
					x.NhapTuHe2((string)res[1]);
					y.NhapTuHe2((string)res[3]);
					x = x ^ y;
					fo << x.LayHe2() << endl;
                }
            }
            //he 10
            if (strcmp(res[0],"10") == 0)     //Kiểm tra hệ cơ số -> TH này làm trên cơ số 10
            {
                if (*res[2] == '+'){     //Kiểm tra phép toán -> TH này là phép +
                    // hàm + cơ số 10
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x + y;
					fo << x.LayHe10() << endl;
                }
                else if (*res[2] == '-'){
                    // hàm - cơ số 10
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x - y;
					fo << x.LayHe10() << endl;
                }
                else if (*res[2] == '*'){
                    // hàm * cơ số 10
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x * y;
					fo << x.LayHe10() << endl;
                }
                else if (*res[2] == '/'){
                    // hàm / cơ số 10
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x / y;
					fo << x.LayHe10() << endl;
                }
                else if (strcmp(res[2],">>") == 0){
                    // hàm dịch phải
					x.NhapTuHe10((string)res[1]);
					int k = atoi(res[3]);
					x = x >> k;
					fo << x.LayHe10() << endl;
                }
                else if (strcmp(res[2],"<<") == 0){
                    // hàm dịch trái
					x.NhapTuHe10((string)res[1]);
					int k = atoi(res[3]);
					x = x << k;
					fo << x.LayHe10() << endl;
                }
                else if (strcmp(res[2],"&") == 0){
                    // ham AND 2 so he 2
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x & y;
					fo << x.LayHe10() << endl;
                }
                else if (strcmp(res[2],"|") == 0){
                    // ham OR 2 so he 2
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x | y;
					fo << x.LayHe10() << endl;
                }
                else if (strcmp(res[2],"^") == 0){
                    // ham XOR 2 so he 2
					x.NhapTuHe10((string)res[1]);
					y.NhapTuHe10((string)res[3]);
					x = x ^ y;
					fo << x.LayHe10() << endl;
                }
            }
            // Hệ 16
            if (strcmp(res[0],"16") == 0)     //Kiểm tra hệ cơ số -> TH này làm trên cơ số 16
            {
                // hàm chuyển cơ số 16 -> QInt
                if (*res[2] == '+'){     //Kiểm tra phép toán -> TH này là phép +
                    // hàm + cơ số 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x + y;
					fo << x.LayHe16() << endl;
                }
                else if (*res[2] == '-'){
                    // hàm - cơ số 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x - y;
					fo << x.LayHe16() << endl;
                }
                else if (*res[2] == '*'){
                    // hàm * cơ số 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x * y;
					fo << x.LayHe16() << endl;
                }
                else if (*res[2] == '/'){
                    // hàm / cơ số 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x / y;
					fo << x.LayHe16() << endl;
                }
                else if (strcmp(res[2],">>") == 0){
                    // hàm dịch phải
					x.NhapTuHe16((string)res[1]);
					int k = atoi(res[3]);
					x = x >> k;
					fo << x.LayHe16() << endl;
                }
                else if (strcmp(res[2],"<<") == 0){
                    // hàm dịch trái
					x.NhapTuHe16((string)res[1]);
					int k = atoi(res[3]);
					x = x << k;
					fo << x.LayHe16() << endl;
                }
                else if (strcmp(res[2],"&") == 0){
                    // ham AND 2 so he 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x & y;
					fo << x.LayHe16() << endl;
                }
                else if (strcmp(res[2],"|") == 0){
                    // ham OR 2 so he 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x | y;
					fo << x.LayHe16() << endl;
                }
                else if (strcmp(res[2],"^") == 0){
                    // ham XOR 2 so he 16
					x.NhapTuHe16((string)res[1]);
					y.NhapTuHe16((string)res[3]);
					x = x ^ y;
					fo << x.LayHe16() << endl;
                }
            }
        }
        // khaong trang  = 2
        if (demKhoangTrang(a) == 2){
            char* p;
            p = chuyenStringSangChar(a);
            vector<char*> res;
            res = tachChuoi(p);
			QInt x;
            // He 2
            if (strcmp(res[0],"2") == 0)     //Kiểm tra hệ cơ số -> TH này làm trên cơ số 2
            {
                // hàm chuyển cơ số 2 -> QInt
				x.NhapTuHe2((string)res[2]);
                // kiểm tra xem có phải là trường hợp chuyển cơ số hay không?
                // Hệ 2 -> 10
                if (strcmp(res[1],"10") == 0){
                    // Hàm chuyển hệ 2 -> 10
					fo << x.LayHe10() << endl;
                }
                // Hệ 2 -> 16
                else if (strcmp(res[1],"16") == 0){
                 // hàm chuyển hệ 2 -> 16
					fo << x.LayHe16() << endl;
                }
                // Kiểm tra phải là phép NOT trên hệ 2 hay không?
                else if (strcmp(res[1],"~") == 0){
                    // ham and 2 so
					x = ~ x;
					fo << x.LayHe2() << endl;
                }
                // Kiểm tra phải phép xoay trái hay không?
                else if(strcmp(res[1],"rol") == 0){
					x = x.rol(1);
					fo << x.LayHe2() << endl;
                }
                // Kiểm tra phải phép xoay phải hay không?
                else if(strcmp(res[1],"ror") == 0){
					x = x.ror(1);
					fo << x.LayHe2() << endl;
                }
            }
            // He 10
            if (strcmp(res[0],"10") == 0)     //Kiểm tra hệ cơ số -> TH này làm trên cơ số 10
            {
                // hàm chuyển cơ số 10 -> QInt
				x.NhapTuHe10((string)res[2]);
                // kiểm tra xem có phải là trường hợp chuyển cơ số hay không?
                // Hệ 10 -> 2
                if (strcmp(res[1],"2") == 0){
                    // Hàm chuyển hệ 10 -> 2
					fo << x.LayHe2() << endl;
                }
                // Hệ 2 -> 16
                else if (strcmp(res[1],"16") == 0){
                    // hàm chuyển hệ 2 -> 16
					fo << x.LayHe16() << endl;
                }
                // Kiểm tra phải là phép NOT trên hệ 2 hay không?
                else if (strcmp(res[1],"~") == 0){
                    // ham NOT 2 so
					x = ~x;
					fo << x.LayHe10() << endl;
                }
                // Kiểm tra phải phép xoay trái hay không?
                else if(strcmp(res[1],"rol") == 0){
					x = x.rol(1);
					fo << x.LayHe10() << endl;
                }
                // Kiểm tra phải phép xoay phải hay không?
                else if(strcmp(res[1],"ror") == 0){
					x = x.ror(1);
					fo << x.LayHe10() << endl;
                }
            }
            // He 16
            if (strcmp(res[0],"16") == 0)     //Kiểm tra hệ cơ số -> TH này làm trên cơ số 16
            {
                // hàm chuyển cơ số 16 -> QInt
				x.NhapTuHe16((string)res[2]);
                // kiểm tra xem có phải là trường hợp chuyển cơ số hay không?
                // Hệ 16 -> 2
                if (strcmp(res[1],"2") == 0){
                    // Hàm chuyển hệ 16 -> 2
					fo << x.LayHe2() << endl;
                }
                // Hệ 16 -> 10
                else if (strcmp(res[1],"10") == 0){
                    // hàm chuyển hệ 16 -> 10
					fo << x.LayHe10() << endl;
                }
                // Kiểm tra phải là phép NOT trên hệ 2 hay không?
                else if (strcmp(res[1],"~") == 0){
                    // ham NOT 2 so
					x = ~x;
					fo << x.LayHe16() << endl;
                }
                // Kiểm tra phải phép xoay trái hay không?
                else if(strcmp(res[1],"rol") == 0){
					x = x.rol(1);
					fo << x.LayHe16() << endl;
                }
                // Kiểm tra phải phép xoay phải hay không?
                else if(strcmp(res[1],"ror") == 0){
					x = x.ror(1);
					fo << x.LayHe16() << endl;
                }
            }
        }
    }
	delete p;
	f.close();
	fo.close();
	system("pause");
    return 0;

}
