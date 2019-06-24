#include <iostream>
#include <math.h>

using namespace std;

void KelasA(){
	int prefix, subnet, mask, jml, pangkat, range, host;
	long int akhir;
	long int x=0;
	long int y=1;

	cout << "\n\t Perhitungan prefix IP Kelas A" << endl;
	cout << "\nMasukkan nilai prefix (/1-7) : /";
	cin >> prefix;

	if(prefix <8 && prefix >= 1){
		pangkat = 8 - prefix;
    	subnet = pow (2, pangkat);
    	mask = 256 - subnet;

    	cout << "Subnet mask dari prefix /" << prefix << " adalah " << mask << ".0.0.0"<< endl;
		range = pow(2, (32 - prefix));
		cout << "Range networknya adlah " << range << " IP" << endl;
		host = range - 2;
		cout << "Jumlah host yang bisa dipakai adalah " << host << endl;

		cout << "\nRange networknya adalah " << endl;
		do{
			cout << "\t10." << x << ".0.0/" << prefix;
			x = x + subnet;
			jml = x - 1;
			cout << " - 10." << jml << ".255.255" <<endl;
		} while (x<=255);

		cout << "\nIP yang bisa dipakai adalah " << endl;
		do{	
			cout << "\t10." << y <<".0.1";
			y = y + subnet;
			akhir = y - 3;
			cout << " - 10." << akhir << ".255.254" << endl;
		} while(y<255);
	} else if(prefix >= 8  && prefix <=30){
		cout << "Prefix " << prefix << " tidak termasuk kelas A!" << endl;
	} else if (prefix==31 || prefix==32 || prefix==0) {
    	cout << "Prefix "<< prefix <<" tidak bisa dikategorikan sebagai jaringan." << endl;
	} else if (prefix >=32){
		cout << "Prefix tidak ditemukan!" << endl;
	}
}

void KelasB(){
	int prefix, subnet, mask, jml, pangkat, range, host;
	short int akhir;
	short int x=0;
	short int y=1;

	cout << "\n\t Perhitungan prefix IP Kelas B" << endl;
	cout << "\nMasukkan nilai prefix (/16-23) : /";
	cin >> prefix;

	if(prefix <24 && prefix >= 16){
		pangkat = 24 - prefix;
		subnet = pow(2, pangkat);
		mask = 256 -subnet;
		
		
		cout << "Subnet mask dari prefix /" << prefix << " adalah 255.255." << mask << ".0"<< endl;
		range = pow(2, (32 - prefix));
		cout << "Range networknya adlah " << range << " IP" << endl;
		host = range - 2;
		cout << "Jumlah host yang bisa dipakai adalah " << host << endl;

		cout << "\nRange networknya adalah " << endl;
		do{
			cout << "\t172.16." << x << ".0/" << prefix;
			x = x + subnet;
			jml = x - 1;
			cout << " - 172.16." << jml << ".255" <<endl;
		} while (x<=255);

		cout << "\nIP yang bisa dipakai adalah " << endl;
		do{	
			cout << "\t172.16." << y <<".1";
			y = y + subnet;
			akhir = y - 3;
			cout << " - 172.16." << akhir << ".254" << endl;
		} while(y<255);
	} else if(prefix < 16 && prefix >= 1){
		cout << "Prefix " << prefix << " tidak termasuk kelas B!" << endl;
	} else if(prefix >= 24 && prefix <=30){
		cout << "Prefix " << prefix << " tidak termasuk kelas B!" << endl;
	} else if (prefix==31 || prefix==32 || prefix==0) {
    	cout << "Prefix "<< prefix <<" tidak bisa dikategorikan sebagai jaringan." << endl;
	} else if (prefix >=32){
		cout << "Prefix tidak ditemukan!" << endl;
	}
}

void KelasC(){
	int prefix, subnet, mask, jml, pangkat, range, host;
	short int akhir;
	short int x=0;
	short int y=1;

	cout << "\n\t Perhitungan prefix IP Kelas C" << endl;
	cout << "\nMasukkan nilai prefix (/24-30) : /";
	cin >> prefix;

	if (prefix <= 30 && prefix >= 24 ){
		pangkat = 32 - prefix;
		subnet = pow(2, pangkat);
		mask = 256 - subnet ;
		host = subnet - 2;
		

		cout << "Subnet mask dari prefix /" << prefix << " adalah 255.255.255." << mask << endl;
		cout << "Range networknya adlah " << subnet << " IP" << endl;
		cout << "Jumlah host yang bisa dipakai adalah " << host << endl;

		cout << "\nRange networknya adalah " << endl;
		do{
			cout << "\t192.168.1." << x << "/" << prefix;
			x = x + subnet;
			jml = x - 1;
			cout << " - 192.168.1." << jml << endl;
		} while (x<=255);

		cout << "\nIP yang bisa dipakai adalah " << endl;
		do{	
			cout << "\t192.168.1." << y;
			y = y + subnet;
			akhir = y - 3;
			cout << " - 192.168.1." << akhir << endl;
		} while(y<255);
	} else if(prefix < 24 && prefix >= 1){
		cout << "Prefix " << prefix << " tidak termasuk kelas C!" << endl;
	} else if (prefix==31 || prefix==32 || prefix==0) {
    	cout << "Prefix "<< prefix <<" tidak bisa dikategorikan sebagai jaringan." << endl;
	} else if (prefix >=32){
		cout << "Prefix tidak ditemukan!" << endl;
	}
}

void displayMenu(){
	int pilihan;
	char yt;

	cout << R"(
		   _____       __               __  __  _            
		  / ___/__  __/ /_  ____  ___  / /_/ /_(_)___  ____ _
		  \__ \/ / / / __ \/ __ \/ _ \/ __/ __/ / __ \/ __ `/
		 ___/ / /_/ / /_/ / / / /  __/ /_/ /_/ / / / / /_/ / 
		/____/\__,_/_.___/_/ /_/\___/\__/\__/_/_/ /_/\__, /  
		                                            /____/   

	               	     ---= [Tugas Akhir C++
	               	      --= [Version  : Beta
	               	       -= [Codename : Subnetting
	            	    <---= xxxxxxxxx = xxxxxxxxxx
	               	       -= Redho Maland Aresta
	               	      --= Ero Wahu Pratomo
	               	     ---= Vicky Geraldino	
	)" << '\n';
	menu :
	cout << "Subnetting menggunakan prefix : " << endl;
	string menu[3] = {"Kelas A", "Kelas B", "Kelas C"};
	for (int i = 1; i < 4; i++)
	{
		cout << i << ".\t" << menu[i - 1] << endl;
	}
	cout << "99.\tExit\n";
	cout << "Masukkan Pilihan Kelas IP : "; cin >> pilihan;

	switch(pilihan){
		case 1:
			KelasA();
			break;
		case 2:
			KelasB();
			break;
		case 3:
			KelasC();
			break;
		case 99:
			cout << "Exit";
			break;

		//cout<<"Apakah anda ingin mengulang ? [Y/T] : ";
		//	cin>>yt;
		//	if(yt=='Y' || yt=='y')
		//		{goto menu;}
		//	if(yt=='T' || yt=='t')
		//		{exit;}
	}
}



int main(){
	displayMenu();
	return 0;
}