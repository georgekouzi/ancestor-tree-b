#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;
    Tree t("Yosef");
TEST_CASE("addFather & addMother"){
t.addFather("Yosef", "Yaakov");  
t.addMother("Yosef", "Rachel");
t.addFather("Yaakov", "Isaac");
t.addMother("Yaakov", "Rivka");
t.addFather("Isaac", "Avraham");
t.addFather("Avraham", "Terah");
t.addMother("Isaac","nofar");
t.addMother("nofar","dana");
t.addMother("dana","dafna");
t.addMother("dafna","yeal");
t.addFather("dafna", "dor");
t.addFather("Rachel", "dan");
t.addMother("dan", "rot");
t.addMother("Rivka", "shir");
t.addFather("Rivka", "shon");
t.addFather("rot", "kobi");
t.addMother("kobi", "dvora");
t.addFather("dvora", "doron");
t.addMother("Rachel", "tamar");
t.addMother("tamar", "sigal");
t.addFather("tamar", "gon");
t.addMother("gon", "tal");
t.addFather("gon", "ben");
t.addMother("ben", "shani");
    
    CHECK(t.getNode()->mother->mother->name=="tamar");
    CHECK(t.getNode()->mother->mother->mother->name=="sigal");
    CHECK(t.getNode()->mother->mother->father->name=="gon");
    CHECK(t.getNode()->mother->mother->father->mother->name=="tal");
    CHECK(t.getNode()->mother->mother->father->father->name=="ben");
    CHECK(t.getNode()->mother->mother->father->father->mother->name=="shani");
    CHECK(t.getNode()->name=="Yosef");
    CHECK(t.getNode()->father->name=="Yaakov");
    CHECK(t.getNode()->mother->name=="Rachel");
    CHECK(t.getNode()->father->father->name=="Isaac");
    CHECK(t.getNode()->father->mother->name=="Rivka");
    CHECK(t.getNode()->father->father->father->name=="Avraham");
    CHECK(t.getNode()->father->father->father->father->name=="Terah");
    CHECK(t.getNode()->father->father->mother->name=="nofar");
    CHECK(t.getNode()->father->father->mother->mother->name=="dana");
    CHECK(t.getNode()->father->father->mother->mother->mother->name=="dafna");
    CHECK(t.getNode()->father->father->mother->mother->mother->mother->name=="yeal");
    CHECK(t.getNode()->father->father->mother->mother->mother->father->name=="dor");
    CHECK(t.getNode()->mother->father->name=="dan");
    CHECK(t.getNode()->mother->father->mother->name=="rot");
    CHECK(t.getNode()->father->mother->mother->name=="shir");
    CHECK(t.getNode()->father->mother->father->name=="shon");
    CHECK(t.getNode()->mother->father->mother->father->name=="kobi");
    CHECK(t.getNode()->mother->father->mother->father->mother->name=="dvora");
    CHECK(t.getNode()->mother->father->mother->father->mother->father->name=="doron");//19
}



TEST_CASE("Test rlation"){  
    CHECK(t.relation("Yosef") =="me");
    CHECK(t.relation("Yaakov") =="father" );
    CHECK(t.relation("Rachel") =="mother" );
    CHECK(t.relation("Isaac") =="grandfather" );
    CHECK(t.relation("Rivka") =="grandmother" );
    CHECK(t.relation("Avraham") =="great-grandfather");
    CHECK(t.relation("Terah") =="great-great-grandfather");
    CHECK(t.relation("nofar") =="great-grandmother");
    CHECK(t.relation("dana") =="great-great-grandmother");
    CHECK(t.relation("dafna") =="great-great-great-grandmother");
    CHECK(t.relation("yeal") =="great-great-great-great-grandmother");
    CHECK(t.relation("dor") =="great-great-great-great-grandfather");
    CHECK(t.relation("dan") =="grandfather");
    CHECK(t.relation("rot") =="great-grandmother");
    CHECK(t.relation("shir") =="great-grandmother");
    CHECK(t.relation("shon") =="great-grandfather");
    CHECK(t.relation("kobi") =="great-great-grandfather");
    CHECK(t.relation("dvora") =="great-great-great-grandmother");
    CHECK(t.relation("doron") =="great-great-great-great-grandfather");//19
    CHECK(t.relation("romi") =="unrelated");
    CHECK(t.relation("") =="unrelated");
    CHECK(t.relation(" ...") =="unrelated");
    CHECK(t.relation("             ") =="unrelated");
     //std::cout << dolev->name << std::endl;

    CHECK(t.relation("tamar") =="grandmother");
    CHECK(t.relation("sigal") =="great-grandmother");
    CHECK(t.relation("gon") =="great-grandfather");
    CHECK(t.relation("tal") =="great-great-grandmother");        
    CHECK(t.relation(" ") =="unrelated");
    CHECK(t.relation("dfdv") =="unrelated");
    CHECK(t.relation("fdd") =="unrelated");
    CHECK(t.relation("ben") =="great-great-grandfather");
    CHECK(t.relation("shani") =="great-great-great-grandmother");
    CHECK(t.relation(" ") =="unrelated");


}

TEST_CASE("Test find"){
    CHECK(t.find("me") =="Yosef");
    CHECK(t.find("father") =="Yaakov" );
    CHECK(t.find("mother") =="Rachel" );
    CHECK(t.find("grandfather") =="Isaac" );
    CHECK(t.find("grandmother") =="Rivka" );
    CHECK(t.find("great-grandfather") =="Avraham");
    CHECK(t.find("great-great-grandfather") =="Terah");
    CHECK(t.find("great-grandmother") =="nofar");
    CHECK(t.find("great-great-grandmother") =="dana");
    CHECK(t.find("great-great-great-grandmother") =="dafna");
    CHECK(t.find("great-great-great-great-grandmother") =="yeal");
    CHECK(t.find("great-great-great-great-grandfather") =="dor");
    CHECK(t.find("grandfather") =="dan");
    CHECK(t.find("great-grandmother") =="rot");
    CHECK(t.find("great-grandmother") =="shir");
    CHECK(t.find("great-grandfather") =="shon");
    CHECK(t.find("great-great-grandfather") =="kobi");
    CHECK(t.find("great-great-great-grandmother") =="dvora");
    CHECK(t.find("great-great-great-great-grandfather") =="doron");//19
    CHECK(t.find("great-great-great-great-great-grandfather") =="unrelated");
    CHECK(t.find("great-great-great-great-great-grandmother") =="unrelated");
    CHECK(t.find("great-great-grandmother") =="sigal");
    CHECK(t.find("great-great-grandfather") =="gon");
    CHECK(t.find("great-great-great-grandfather") =="ben");
    CHECK(t.find("great-great-great-grandmother") =="tal");
    CHECK(t.find("great-great-great-great-grandmother") =="shani");

}  











TEST_CASE("Test remove"){


t.remove("doron");
    CHECK("unrelated"==t.relation("doron") );    

 t.remove("yeal");
     CHECK("unrelated"==t.relation("yeal") );    

 t.remove("dafna");
    CHECK("unrelated"==t.relation("dafna") );    

 t.remove("dana");
     CHECK("unrelated"==t.relation("dana") );    

 t.remove("nofar");
     CHECK("unrelated"==t.relation("nofar") );    

t.remove("Terah");
    CHECK("unrelated"==t.relation("Terah") );    

t.remove("Avraham");
    CHECK("unrelated"==t.relation("Avraham") );    

t.remove("Isaac");
    CHECK("unrelated"==t.relation("Isaac") );    

t.remove("shon");
    CHECK("unrelated"==t.relation("shon") );    

t.remove("shir");
    CHECK("unrelated"==t.relation("shir") ); 

t.remove("Rivka");
    CHECK("unrelated"==t.relation("Rivka") ); 

t.remove("Yaakov");
    CHECK("unrelated"==t.relation("Yaakov") ); 

 //t.remove("doron");
   //  CHECK("unrelated"==t.relation("doron") ); 

t.remove("dvora");
     CHECK("unrelated"==t.relation("dvora") ); 

t.remove("kobi");
    CHECK("unrelated"==t.relation("kobi") ); 

t.remove("rot");
    CHECK("unrelated"==t.relation("rot") ); 

t.remove("dan");
    CHECK("unrelated"==t.relation("dan") );    
       
t.remove("tamar");
    CHECK("unrelated"==t.relation("tamar") );

//  t.remove("sigal");
//      CHECK("unrelated"==t.relation("sigal") );

// t.remove("gon");
//     CHECK("unrelated"==t.relation("gon") );

// t.remove("tal");
//     CHECK("unrelated"==t.relation("tal") );

// t.remove("ben");
//     CHECK("unrelated"==t.relation("ben") );

// t.remove("shani");
//     CHECK("unrelated"==t.relation("shani") );        

// t.remove("Rachel");
//     CHECK("unrelated"==t.relation("Rachel") );


// t.remove("Yosef");
//     CHECK("unrelated"==t.relation("Yosef") );
//     ////////////////////////////////////////////////



    




}









