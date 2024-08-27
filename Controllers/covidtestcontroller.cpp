#include "covidtestcontroller.h"

CovidTestController::CovidTestController()
{
    fstream ValidarArchivo(fileName,ios::in);
    if(!ValidarArchivo){
    fstream CreateFile(fileName,ios::out);
    CreateFile<<"id,temperaturaCorporal,tos,gusto,cansancio,dolor de garganta, "
    <<"Dolor de cuerpo,Dolor de cabeza, Dolor de pecho, diarrea, conjuntivitis, Probabilidad de contagio"<<endl;
    }
}

void CovidTestController::SaveTest(CovidTest *test)
{
     //obtenemos numero de lineas que ya estan escritas y no debemos tomar en cuenta
     File.open(fileName);
     int cuenta=0;
     string line;
     vector<string> lineas;
    while(getline(File,line)){
              ++cuenta;
              lineas.push_back(line);
              }
    File.close();


    File.open(fileName);
    if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;
    if (File.is_open()) {

        int id =test->getid();
        int temperaturaCorporal = test->getTemperaturaCorporal();
        string tos = test->getTos(); //frecuente
        int olfato = test->getOlfato(); //del 0 al 10 cuanto huele
        int gusto = test->getGusto(); // del 0 al 10 cuanto saborea
        int cansancio = test->getCansancio(); // del 0 al 10 que tan cansado
        int dolorGarganta = test->getDolorGarganta(); // 0 al 10
        int dolorCuerpo = test->getDolorCuerpo(); // 0 al 10
        int dolorCabeza = test->getDolorCabeza(); // 0 al 10 frecuencia
        int dolorPecho = test->getDolorPecho(); // le duele el pecho
        string diarrea = test->getDiarrea(); // tiene diarrea
        string conjuntivitis = test->getConjuntivitis(); // le pican los ojos
        float contegio = test->getPorcentajeContagio();

        do{
            for(int i = 0; i<cuenta;++i){
            File<<lineas[i]<<endl; //sobreescribimos las lineas y al final ponemos la nueva
                if(i == cuenta-1){
                File<<to_string(id)<< ","
                        <<to_string(temperaturaCorporal)<<","
                        <<tos<<","
                        <<to_string(olfato)<<","
                        <<to_string(gusto)<<","
                        <<to_string(cansancio)<<","
                        <<to_string(dolorGarganta)<<","
                        <<to_string(dolorCuerpo)<<","
                        <<to_string(dolorCabeza)<<","
                        <<to_string(dolorPecho)<<","
                        <<diarrea<<","
                        <<conjuntivitis<<","
                        <<to_string(contegio)<<endl;
                }
            }

            cout<<"Guardado con exito!"<<endl;
        }while(false);
    }else{
    cout<<"Error al abrir archivo";
    }
    File.close();

}


CovidTest *CovidTestController::getTest(int id)
{
    string line ;
        vector<string> covidData;

        File.open(fileName);
        if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;
        while(getline(File,line))
        {
        covidData= split(line,",");
         if(covidData[0] == "Id")continue;
         if(covidData[0]== to_string(id)){
         break;
         }
        }
        File.close();

        CovidTest *covidTest = new  CovidTest();

        covidTest->setid(stoi(covidData[0]));
        covidTest->setTemperaturaCorporal(stoi(covidData[1]));
        covidTest->setTos(covidData[2]);
        covidTest->setOlfato(stoi(covidData[3]));
        covidTest->setGusto(stoi(covidData[4]));
        covidTest->setCansancio(stoi(covidData[5]));
        covidTest->setDolorGarganta(stoi(covidData[6]));
        covidTest->setDolorCuerpo(stoi(covidData[7]));
        covidTest->setDolorCabeza(stoi(covidData[8]));
        covidTest->setDolorPecho(stoi(covidData[9]));
        covidTest->setDiarrea(covidData[10]);
        covidTest->setConjuntivitis(covidData[11]);
        covidTest->setPorcentajeContagio(stoi(covidData[12]));

        return  covidTest;
}

bool CovidTestController::ValidTestId(int id)
{
 File.open(fileName);
     if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;
     string line;
     string ids;
    vector<int> TestsId;

    while(getline(File,line))
        {
        ids = splitId(line,",");
        if(ids == "Id")continue;

        try{
            TestsId.push_back(stoi(ids));
        } catch (...) {
        continue;
        }

         }
         File.close();

         vector<int >::iterator it;
         for (it = TestsId.begin();
                 it != TestsId.end();
                 it++) {

                  if(*it == id){
                      return true;
                  }
          }

    return false;
}


