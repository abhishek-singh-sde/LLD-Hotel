#include <bits/stdc++.h>
using namespace std;

int iequals(string a, string b);
int iequals(string a, string b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return 0;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return 0;
    return 1;
}

class user 
{
  string name;
  string email;
  
  public:
  void setUserDetails()
  {
   cout<<"Enter Full Name:"<<endl;
   getline(cin,name);
   cout<<"Enter E-Mail ID:"<<endl;
   getline(cin,email);
  }
  
  void printUserDetails()
  {
   cout<<name<<" "<<email<<endl;
  }
};

class Hotel
{
    string city;
    int pincode;
    string place;
    float ratings;
    int availableRooms;
    string id;
    public:
    
    Hotel()
    {
     city="No_Input_City";
     pincode=0;
     place="No_Input_Place";
     ratings=4.56;
     availableRooms=5;
     id="ID000";
    }
    
    Hotel(string passed_place,string passed_city,int passed_pincode,float passed_ratings,int passed_availableRooms,string passed_id)
    {
     city=passed_city;
     pincode=passed_pincode;
     place=passed_place;
     ratings=passed_ratings;
     availableRooms=passed_availableRooms;
     id=passed_id;
    }
    
    void setHotelDetails()
    {
     cout<<"Enter Place:"<<endl;
     cin.ignore();
     getline(cin,place);
     cout<<"Enter City:"<<endl;
     cin.ignore();
     getline(cin,city);
     cout<<"Enter PinCode:"<<endl;
     cin>>pincode;
     cout<<"Enter number of Available Rooms:"<<endl;
     cin>>availableRooms;
     cout<<"Enter Ratings:"<<endl;
     cin>>ratings;
     cout<<"Enter ID:"<<endl;
     cin>>id;
    }
    
    void printHotelDetails()
    {
     cout<<"Place: "<<place<<endl;
     cout<<"City: "<<city<<endl;
     cout<<"Pincode: "<<pincode<<endl;
     cout<<"Number of Available Rooms: "<<availableRooms<<endl;
     cout<<"Rating: "<<ratings<<endl;
     cout<<"ID: "<<id<<endl;
    }
    
    Hotel filterByPincode(Hotel H,int query_pincode)
    {
     if(H.pincode==query_pincode)
      return H;
     else
      return Hotel("X","Y",-1,-1,-1,"Z"); //This indicates no match found.
    }
    
    Hotel filterByPlace(Hotel H,string query_place)
    {
     if(iequals(H.place,query_place)==1)
      return H;
     else
      return Hotel("X","Y",-1,-1,-1,"Z"); //This indicates no match found.
    }
    
    Hotel filterByCity(Hotel H,string query_city)
    {
     if(iequals(H.city,query_city)==1)
      return H;
     else
      return Hotel("X","Y",-1,-1,-1,"Z"); //This indicates no match found.
    }
    
    Hotel filterByRatings(Hotel H,float query_ratings)
    {
     if(H.ratings>=query_ratings)
      return H;
     else
      return Hotel("X","Y",-1,-1,-1,"Z"); //This indicates no match found.
    }
    
    Hotel searchByID(Hotel H,string query_ID)
    {
     if(H.id==query_ID)
      return H;
     else
      return Hotel("X","Y",-1,-1,-1,"Z"); //This indicates no match found.
    }
    
    int getPin(Hotel H)
    {
     return H.pincode;
    }
};

int main()
{
 char ch='y';
 int n=5;
 Hotel H[50];
 H[0]=Hotel("Karol Bag 1","New Delhi",100005,4.72,7,"ID001");
 H[1]=Hotel("Karol Bag 2","new delhi",100006,3.84,6,"ID002");
 H[2]=Hotel("Karol Bag 3","New Surat",100007,4.63,8,"ID003");
 H[3]=Hotel("Karol Bag 4","nEw surat",100008,2.61,9,"ID004");
 H[4]=Hotel("Karol Bag 5","New delHi",100009,4.91,7,"ID005");
 int q_no,i;
 int query_pincode;
 float query_ratings;
 string query_place,query_city,query_ID;
 while((ch=='y') || (ch=='Y'))
 {
  cout<<"Enter your choice:"<<endl;
  cout<<"1. Search by place"<<endl;
  cout<<"2. Search by city"<<endl;
  cout<<"3. Search by pincode"<<endl;
  cout<<"4. Search by ratings"<<endl;
  cout<<"5. Add a new hotel"<<endl;
  cout<<"6. Enter a Hotel ID for booking"<<endl;
  cout<<"NOTE: Use the ID of Hotel in search results for booking further. Thanks!"<<endl;
  cin>>q_no;
  
  if(q_no==1)
  {
   vector<Hotel>result;
   cout<<"Enter the place to be searched:"<<endl;
   cin.ignore();
   getline(cin,query_place);
   for(i=0;i<n;i++)
   {
    Hotel Temp=H[i].filterByPlace(H[i],query_place);
    if(Temp.getPin(Temp)!=-1)
     result.push_back(H[i].filterByPlace(H[i],query_place));
   }
   for(auto x: result)
    x.printHotelDetails();
  }
 
  if(q_no==2)
  {
   vector<Hotel>result;
   cout<<"Enter the city to be searched:"<<endl;
   cin.ignore();
   getline(cin,query_city);
   for(i=0;i<n;i++)
   {
    Hotel Temp=H[i].filterByCity(H[i],query_city);
    if(Temp.getPin(Temp)!=-1)
     result.push_back(Temp);
   }
   for(auto x: result)
    x.printHotelDetails();
  }
 
  if(q_no==3)
  {
   vector<Hotel>result;
   cout<<"Enter the pincode to be searched:"<<endl;
   cin>>query_pincode;
   for(i=0;i<n;i++)
   {
    Hotel Temp=H[i].filterByPincode(H[i],query_pincode);
    if(Temp.getPin(Temp)!=-1)
     result.push_back(Temp);
   }
   for(auto x: result)
    x.printHotelDetails();
  }
 
  if(q_no==4)
  {
   vector<Hotel>result;
   cout<<"Enter the cutoff ratings:"<<endl;
   cin>>query_ratings;
   for(i=0;i<n;i++)
   {
    Hotel Temp=H[i].filterByRatings(H[i],query_ratings);
    if(Temp.getPin(Temp)!=-1)
    result.push_back(Temp);
   }
   for(auto x: result)
    x.printHotelDetails();
  }
 
  if(q_no==5)
  {
   H[n].setHotelDetails();
   n++;
  }
 
  if(q_no==6)
  {
   vector<Hotel>result;
   cout<<"Enter the ID of the Hotel for booking:"<<endl;
   cin>>query_ID;
   for(i=0;i<n;i++)
   {
    Hotel Temp=H[i].searchByID(H[i],query_ID);
    if(Temp.getPin(Temp)!=-1)
     result.push_back(Temp);
   }
   cout<<"The details of the hotel you selected for booking are as follows:"<<endl;
   result[0].printHotelDetails();
  }
 
  cout<<"Do you want to search or book more hotels? (y/n)"<<endl;
  cin>>ch;
 }
 return 0;
}

