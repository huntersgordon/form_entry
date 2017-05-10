//created by hunter gordon ;)

#include <iostream>
#include <string>
using namespace std;

string run(string cmd);
void print(string urls[],unsigned els);
int main(){
     cout<<"query: ";
     string query;
     getline(cin,query);
     cout << "number of results: ";
     string num_of_urls;
     cin >> num_of_urls;
     string urlarray [stoi(num_of_urls)];
     //string urls = run("googler \"Enter for a chance to win\" -t=d1 -n="+ num_of_urls +" --json");
     string urls = run("googler \""+ query + "\" -t=d1 -n="+ num_of_urls +" --json");
     string raw = urls;
     string intended_url = "";
     string output = "";
     //string output = run("curl " + intended_url + " > index.html ; perl formfind.pl < index.html");
     //output = output.substr(output.find("FORM report"),output.length());
     //cout<<output<<endl;
     for(int i = 0; i < stoi(num_of_urls); i++){
          urls = urls.substr(urls.find("\"url\":") + 6,urls.length());
          urlarray[i] = urls.substr(2,urls.find("}")-6);
          cout<<to_string(i)+": " + urlarray[i]<<endl;
     }

     string input = "";


     cout<<"Enter index of form you want to find, or custom url. q to exit."<<endl;
     cout<<"\"list\" to display urls again."<<endl;

     bool printy = true;
     while(true){

          printy = true;
          cin >> input;
          if (input == "q"){
               break;
          }
          else if (input.length() >2){
               if (input == "list"){
                    print(urlarray,stoi(num_of_urls));
                    printy = false;
               }
               else if (input == "raw"){
                    cout<<raw;
                    printy = false;
               }
               else{
                    intended_url = input;
               }
          }
          else{
               intended_url = urlarray[stoi(input)];
          }
          if(printy){
               cout<<"running formind on: "<<intended_url<<endl;
               run("curl " + intended_url + " > index.html");
               string output = run("perl formfind.pl < index.html");
               cout<<output<<endl;
          }

     }




     return 0;

}

string run(string cmd) {
     //creds to Jeremy Morgan, jeremymorgan.com
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
    while (!feof(stream))
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
    }
    return data;
    }

void print(string urls[],unsigned els){

     for(unsigned i = 0; i < els;i++){

          cout<<to_string(i)+": " + urls[i]<<endl;


     }



}
