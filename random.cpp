// other Teammate responsible for this code
#include "random.h"

string generateSol(){
    srand(time(0)); //random

    int eqCount = 0; //delete later
    string firstEq;
    bool firstEqFound = false;

    do{ //copy everything in this loop, don't forget srand(time(0))

        int n1, n2, n3, n4;
        char opr1, opr2, opr3;
        bool n3exists = false; //if n3 exists, opr2 must also exist
        bool n1has1digit, n1has2digit, n1has3digit, n1has4digit;
        bool n2has1digit, n2has2digit, n2has4digit;
        bool n3has1digit, n3has2digit;
        bool leftComplete = false; //true if left side of equation is complete

        stringstream outSS;
        string equation; //read equation

        //initializing resetting variables
        n1 = n2 = n3 = n4 = 99999;
        opr1 = opr2 = opr3 = '?';
        n1has1digit=n1has2digit=n1has3digit=n1has4digit=false;
        n2has1digit=n2has2digit=n2has4digit=false;
        n3has1digit=n3has2digit=false;

        //n1 and n2 CONDITIONS START HERE

        int n1tmp = rand()% 20;
        if (n1tmp == 0){ //10% chance
            //AAAA+B=C
            n1has4digit = true;
        }
        else{
            n1tmp = rand()% 3;
            switch(n1tmp){ //n1 is random number, 33% chance of 1,2,or 3 digits
                case 0: n1 = rand()% 10;
                    n1has1digit = true; break; //one digit
                case 1: n1 = (rand()% 90) + 10;
                    n1has2digit = true; break; //two digit
                case 2: n1 = (rand()% 900) + 100;
                    n1has3digit = true; break; //three digit
            }
        }

        if (n1has1digit){
            int op1tmp = rand()% 20;
            if (op1tmp == 0){ //5% chance
                //A+BBBB=DD
                n1 = 0;
                n2has4digit = true;
                n3exists = false; //same as default
                opr1 = '*'; //must be *
                n2 = (rand()% 9000) + 1000; //n2 is 4 digit number
                leftComplete = true; //A+BBBB=DD: DONE
            }
            else {
                op1tmp = rand()% 20;
                if (op1tmp < 5){ //25% chance
                    //A+B+C=DD
                    n2has1digit = true;
                    n3has1digit = true;
                }
                else if (op1tmp < 9){ //20% chance
                    //A+B+CC=D
                    n2has1digit = true;
                    n3has2digit = true;
                }
                else if (op1tmp < 13){ //20% chance
                    //A+BB+C=D
                    n2has2digit = true;
                    n3has1digit = true;
                }
                else { //35% chance
                    //A+BB=DDD
                    n2has2digit = true;
                    n3exists = false;
                }

                op1tmp = rand()% 4; // op1 is random operator
                switch(op1tmp){
                    case 0: opr1 = '+'; break;
                    case 1: opr1 = '-'; break;
                    case 2: opr1 = '*'; break;
                    case 3: opr1 = '/'; break;
                }

            }
        }

        else if (n1has2digit){ //if n1 has 2 digits
            n1tmp = rand()% 9;
            if (n1tmp < 2){ //20% chance
                //AA+B+C=D
                n2has1digit = true;
                n3exists = true;
                n3has1digit = true;
                int op1tmp = rand()% 4; // op1 is random operator
                switch(op1tmp){
                    case 0: opr1 = '+'; break;
                    case 1: opr1 = '-'; break;
                    case 2: opr1 = '*'; break;
                    case 3: opr1 = '/'; break;
                }
            }
            else if (n1tmp < 6){ //40% chance
                //AA+BB=DD
                n2has2digit = true;
                n3exists = false; //stay false
                int op1tmp = rand()% 2;
                switch(op1tmp){ //opr1 can only be + or -
                    case 0: opr1 = '+'; break;
                    case 1: opr1 = '-'; break;
                }
            }
            else {//40% chance
                //AA+B=DDD
                n2has1digit = true;
                int op1tmp = rand()% 2;
                switch(op1tmp){ //opr1 can only be + or -
                    case 0: opr1 = '+'; break;
                    case 1: opr1 = '*'; break;
                }
            }
        }

        else if (n1has3digit){ //if n1 has 3 digits
            n1tmp = rand()% 2;
            if (n1tmp == 0){ //50% chance
                n2has1digit = true;
            }
            else { //50% chance
                n2has2digit = true;
            }

            int op1tmp = rand()% 2;
            switch(op1tmp){
                case 0: opr1 = '/'; break;
                case 1: opr1 = '-'; break;
            }

        }

        else if(n1has4digit){ //if n1 has 4 digits
            n2has1digit = true;
            n2 = 0;
            opr1 = '*';
            n3exists = false; //same as default
            n1 = (rand()% 9000) + 1000; //n1 is 4 digit number
            leftComplete = true; //AAAA+B=D: DONE
        }

        if(!leftComplete){ //if n3 does not exist
            if (n2has1digit){
                if (opr1 == '/'){
                    n2 = (rand()% 9) + 1;
                }
                else {
                    n2 = rand()% 10;
                }
            }
            else if (n2has2digit){
                n2 = (rand()% 90) + 10;
            }
            if (!n3exists){
                //AA+BB=DD: DONE
                //AAA+B=DD: DONE
                //AAA+BB=D: DONE
                //AA+B=DDD: DONE
                //A+BB=DDD: DONE
                leftComplete = true;
            }
        }

        //n1 and n2 CONDITIONS END HERE
        //n3 CONDITIONS START HERE

        if (!leftComplete){ //if n3 exists
            if (n2has1digit){ //n2 has 1 digit
                if (n1has1digit){ //n1 has one digit
                    int n3tmp = rand()% 2;
                    if (n3tmp == 0){
                        //A+B+C=DD
                        n3has1digit = true; //50% chance
                    }
                    else{
                        //A+B+CC=D
                        n3has2digit = true; //50% chance
                    }
                }
                else if (n1has2digit){ //n1 has 2 digits
                    //AA+B+C=D
                    n3has1digit = true;
                }
            }

            else if (n2has2digit){
                //A+BB+C
                n3has1digit = true;
            }

            int op2tmp = rand()% 4; //op2 is random operator
            switch(op2tmp){
                case 0: opr2 = '+'; break;
                case 1: opr2 = '-'; break;
                case 2: opr2 = '*'; break;
                case 3: opr2 = '/'; break;
            }
            if (n3has1digit && opr2 == '/'){ //n3 cannot be 0
                n3 = (rand()% 9) + 1;
            }
            else if (n3has1digit){ //n3 has one digit
                n3 = rand()% 10;
            }
            else if (n3has2digit){ //n3 has two digits
                n3 = (rand()% 90) + 10;
            }
            //A+B+C=DD: DONE
            //A+B+CC=D: DONE
            //AA+B+C=D: DONE
            //A+BB+C=D: DONE
            leftComplete = true; //DONE
        }

        //n3 CONDITIONS END HERE

        if (leftComplete){
            opr3 = '='; //op3 is always '='
        }

        //parsing the equation into a readable string
        outSS.str(""); //clear the stringstream
        outSS << n1 << opr1 << n2;
        if (n3exists){
            outSS << opr2 << n3;
        }

        equation = outSS.str(); //equation!

        n4 = findSolAnswer(equation); //n4 is answer to equation

        outSS << opr3 << n4;
        equation = outSS.str(); //equation now has equal sign and answer
        cout << "equation is " << equation << endl;

        if (n4 == -2){
            cout << "Answer is fraction: WRONG" << endl; //fraction answer
        }
        else if (n4 == -1){
            cout << "Answer is negative: WRONG" << endl; //negative answer
        }
        else if (equation.size() == 8){
            if (evaluate(equation)){
                cout << "Equation is true: TRUE" << endl; //true answer
                if (!firstEqFound){ //if equation is found, put into firstEq
                    firstEq = equation;
                }
                firstEqFound = true; //terminate ENTIRE function
            }
            else{
                cout << "Equation is false: WRONG" << endl; //false answer
            }
        }
        else {
            cout << "Equation is not 8 characters: WRONG" << endl; //invalid length
        }

        eqCount++;
        cout << endl;

    } while(!firstEqFound);

    cout << "SUMMARY" << endl;
    cout << "number of attempted equations: " << eqCount << endl;

    if (firstEqFound){
        cout << "solution found: " << firstEq << endl;
        return firstEq;
    }
    else{
        cout << "no solution found" << endl;
        return "00000000"; //default no solution
    }

}

int findSolAnswer(string a){
    int n1, n2, n3;
    char opr1, opr2; //no opr3 or n4
    bool n3exists = false;
    stringstream ss;
    bool null = false;

    ss.clear();
    ss << a;
    ss >> n1 >> opr1 >> n2; //parsing

    while (!ss.eof()){ //parse opr2 and n3 if they exist
        ss >> opr2 >> n3;
        n3exists = true;
    }

    if (!n3exists){ //account for opr2 and n3
        opr2 = '+'; //temporary variables
        n3 = 0;
        ss >> opr2 >> n3;
    }

    if (opr1 == '/'){
        if (n1 < n2){
            null = true;
        }
        else if (n1 % n2 != 0){
            null = true;
        }
    }
    if (opr2 == '/'){
        if (n2 < n3){
            null = true;
        }
        else if (n2 % n3 != 0){
            null = true;
        }
    }

    if((opr2=='*' || opr2=='/') && (opr1!='*' || opr1!='/')){ //PEMDAS necessary

        switch(opr2){
        case '*': n2 = n2 * n3; break;
        case '/': n2 = n2 / n3; break;
        }

        switch(opr1){
        case '+': n2 = n1 + n2; break;
        case '-': n2 = n1 - n2; break;
        }
    }
    else{ //opr2 is not * or /, no PEMDAS necessary

        switch(opr1){
            case '+': n2 = n1 + n2; break;
            case '-': n2 = n1 - n2; break;
            case '*': n2 = n1 * n2; break;
            case '/': n2 = n1 / n2; break;

        }
        switch(opr2){
            case '+': n2 = n2 + n3; break;
            case '-': n2 = n2 - n3; break;
            case '*': n2 = n2 * n3; break;
            case '/': n2 = n2 / n3; break;
        }
    }
    if (null){
        return -2;
    }
    else if (n2 < 0){
        return -1;
    }
    else{
        return n2;
    }

}

//THIS FUNCTION IS ALREADY IN THE MAIN FILE, REDUNDANCY
//EVALUATE STARTS HERE

bool evaluate(string input){
    int n1, n2, n3, n4;
    char opr1, opr2, opr3;
    stringstream ss;
    bool flag;

    ss << input;
    ss >> n1;
    ss >> opr1;
    ss >> n2;
    ss >> opr2;
    ss >> n3;
    if(opr2 != '='){
        ss >> opr3;
        ss >> n4;
    }

    if(opr2 == '='){ //n1 and n2 only
        switch(opr1){
            case '+': n2 = n1 + n2; break;
            case '-': n2 = n1 - n2; break;
            case '*': n2 = n1 * n2; break;
            case '/': n2 = n1 / n2; break;
        }

        flag = n2 == n3;
    }
    else{ //n3 exists
        if((opr2=='*' || opr2=='/') && (opr1!='*' || opr1!='/')){ //opr2 is * or /
            switch(opr2){
            case '*': n2 = n2 * n3; break;
            case '/': n2 = n2 / n3; break;
            }

            switch(opr1){
            case '+': n2 = n1 + n2; break;
            case '-': n2 = n1 - n2; break;
            }
            flag = n2 == n4;
        }
        else{ //opr2 is not * or /
            switch(opr1){
                case '+': n2 = n1 + n2; break;
                case '-': n2 = n1 - n2; break;
                case '*': n2 = n1 * n2; break;
                case '/': n2 = n1 / n2; break;

            }
            switch(opr2){
                case '+': n2 = n2 + n3; break;
                case '-': n2 = n2 - n3; break;
                case '*': n2 = n2 * n3; break;
                case '/': n2 = n2 / n3; break;
            }
            flag = n2 == n4;
        }
    }
    return flag;
}

//EVALUATE ENDS HERE

