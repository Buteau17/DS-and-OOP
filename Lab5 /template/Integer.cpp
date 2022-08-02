#include "Integer.h"

Integer::Integer(string number)
{
  // cout << "string " << number ; cout << "en" << '\n';
  // cout << number.size() << '\n';
	//TODO: read the string and construct the huge integer
  num.resize(1000, 0);
  for(int i=999 , k=number.size()-1 ; k>=0 && i>=0 ; k--, i--){
  //num[i]=number[k];
  if ('0'<=number[k] && number[k]<='9') num[i]=number[k]-'0';
  else num[i]=number[k]-'a'+10;
  // cout << "numk" << number[k] << '\n';
  }

}

Integer Integer::operator +(const Integer& b) {
	//TODO: perform + opearion overloading


  vector<int> bnum=b.getnum();
  Integer result("");
  int carry=0;
  for(int i=999; i>=0; i--){
    if (num[i]+bnum[i]+carry >=16){
    result.setnum(num[i]+bnum[i]+carry-16, i);
    carry =1;
  }
  else{
    result.setnum(num[i]+bnum[i]+carry, i);
    carry=0;
  }
  }
  return result;
}
Integer Integer::operator -(const Integer& b) {
	//TODO: perform - opearion overloading
  const vector<int> bnum=b.getnum();
  Integer result("");
  int borrow=0;
  for(int i=999; i>=0; i--){
    if (num[i]-bnum[i]-borrow<0){
    result.setnum(num[i]-bnum[i]-borrow+16, i);
    borrow =1;
  }
  else{
    result.setnum(num[i]-bnum[i]-borrow, i);
    borrow=0;
  }
  }
  return result;
}



ostream& operator << (ostream& out, const Integer& b) {
	//TODO: perform output overloading
  bool mode=0;
  for (int i =0 ; i<=999; i++){
    if (b.num[i]!=0){
      mode=1;

    }
    if (mode==1){
      if(b.num[i]<=9){
        out<<b.num[i];
      }
      else{
        out<<(char)(b.num[i]+'a'-10);
      }
    }
  }
  if(mode == 0) out << "0";
  return out;
}
