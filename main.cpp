#include <iostream>
#include <climits>
#include <limits>

const char EOS=NULL;
bool neg=false;
int count=0;
int ogranicznik;


/////////////////////////////////////STRING/////////////////////////////////////////////////
typedef struct stringList{
    char value;
    int index;
    struct stringList*next;
    struct stringList*previous;
}ELEMENT;
class String {

private:
    typedef struct {
        ELEMENT *first;
        ELEMENT *last;
    } INFO;

    friend std::istream &operator>>(std::istream &in, String &str) {
        char inp[1000];
        in.getline(inp, sizeof(inp) );
        int i = 0;
        while (inp[i] != NULL) {
            str.add(inp[i]);
            i++;
        }
        str.add(' ');
        return in;
    };

public:
    INFO inf;
    int size;
    char *name;

    String(){
        inf.first=inf.last=NULL;
        name=NULL;
        size=0;
    };
    String(char *tab){
        inf.first=inf.last=NULL;
        int i=0;
        while(tab[i]!=NULL){
            add(tab[i]);
            i++;
        }
    }
    int indexOf(char c){
        ELEMENT *wsk=inf.first;
        while(wsk!= NULL){
            if(wsk->value==c){
                return wsk->index;
            }
            wsk=wsk->next;
        }
        return -1;
    }
    void add(char c){
        ELEMENT *q = new ELEMENT;
        q->value=c;
        q->next=NULL;
        if(isEmpty()) {
            q->previous=NULL;
            q->index=0;
            size=0;
            inf.first=inf.last=q;
        }
        else{
            q->index=(inf.last->index)+1;
            q->previous = inf.last;
            inf.last->next=q;
            inf.last=q;
        }
        size++;
        toName();
    }
    bool isEmpty(){
        return (inf.first==NULL);
    }
    static int sizeOf(String a){
        return a.inf.last->index+1;
    }

    void clean(){
        inf.first=inf.last=NULL;
    }
    void read(){
        ELEMENT *q=inf.first;
        while(q!=NULL){
            std::cout<<q->value;
            q=q->next;
        }
    }
    void toName(){
        name=(char*)calloc(size,sizeof(char));
        ELEMENT *q=inf.first;
        int i=0;
        for(i;i<size;i++){
            name[i]=q->value;
            q=q->next;
        }
        name[i]='\0';

    }
    ~String(){

    };
    char &operator[](std::size_t index){
        ELEMENT *q=inf.first;
        while(q!=NULL){
            if(q->index==index) return q->value;
            q=q->next;
        }
        return q->value;
    }
    String *operator=(char *tab){
        clean();
        int i=0;
        while(tab[i]!=NULL){
            add(tab[i]);
            i++;
        }
        return this;
    }

    ///STRING COMPARATOR
    static bool comparator(String a, String b){
        if(a.size!=b.size) return 0;
        else{
            int i=0;
            while(i<a.size){
                if(a[i]!=b[i]) return 0;
                i++;
            }
        }
        return 1;
    }
};

////////////////////////MEMORY///////////////////////////////////////
typedef struct listMemory{
    String *name;
    int value;
    listMemory *next;
}BLOCK;

class Memory{
    typedef struct {
        listMemory *first;
        listMemory *last;
    } INFO;

public:
    size_t globals;
    INFO inf;

    Memory(){
        inf.first=inf.last=NULL;
        globals=0;
        counter=0;
    }
    void add(char *toAdd){
        BLOCK *q = new BLOCK;
        q->name=new String(toAdd);
        q->value=INT_MIN;
        q->next=NULL;
        if(isEmpty()) {
            inf.first=inf.last=q;
        }
        else{
            inf.last->next=q;
            inf.last=q;
        }
    }
    bool isEmpty(){
        return (inf.first==NULL);
    }
    BLOCK* find(String toFind){
        BLOCK *q=inf.first;
        while(q!=NULL){
            if(String::comparator(*q->name,toFind))
                return q;
            q=q->next;
        }
        return NULL;
    }
    void read(){
        BLOCK *q=inf.first;
        int i=0;
        while(i<globals){
            if(q->value==INT_MIN)
                std::cout<<q->name->name << " Nul" <<std::endl;
            else
                std::cout<<q->name->name << " "<<q->value<<std::endl;
            q=q->next;
            i++;
        }
    }

    ///JUST FOR THE SECOND LINE OF INPUT
    void convertToVariables(const String toConvert){
        ELEMENT *q = toConvert.inf.first;
        String temp;
        while(q!=NULL){
            if(q->value!=' '){
                temp.add(q->value);
                if(q->next==NULL || q->next->value==' '){
                    add(temp.name);
                    globals++;
                    temp.clean();
                }
            }
            q=q->next;
        }
    }
    size_t counter;
};

Memory mem;
/////////////////////EXPRESSIONS/////////////////////////////////////////

//////PARENT
class Phrase{
public:
    virtual int equal()=0;
    Phrase(){
    }
};

////CONSTANT
class Constant : public Phrase {
    int value;
public:
    Constant(int v) : value(v){}
    virtual int equal(){
        return value;
    }
};


////OPERATOR
class Operator : public Phrase {
    char symbol;
    Phrase *left, *right;

public:
    Operator(char s, Phrase *l, Phrase *r) : symbol(s), left(l), right(r) {}
    virtual int equal(){
        int a=0,b=0;
        count++;
        if(count>ogranicznik){
            std::cout<<count-1<<std::endl;
            mem.read();
            exit(0);
        }
        switch(symbol){
            case '*':
                a= left->equal();
                b= right->equal();
                if(a==INT_MIN || b==INT_MIN) return INT_MIN;
                else return a*b;
            case '+':
                a= left->equal();
                b= right->equal();
                if(a==INT_MIN || b==INT_MIN) return INT_MIN;
                else return a+b;
            case '-':
                a= left->equal();
                b= right->equal();
                if(a==INT_MIN || b==INT_MIN) return INT_MIN;
                else return a-b;
            case '/':
                a= left->equal();
                b= right->equal();
                if(a==INT_MIN || b==INT_MIN) return INT_MIN;
                else if(b==0) return INT_MIN;
                else return a/b;
            case '%':
                a= left->equal();
                b= right->equal();
                if(a==INT_MIN || b==INT_MIN) return INT_MIN;
                else if(b==0) return INT_MIN;
                else return a%b;
            case '<':
                if(left->equal()< right->equal()) return 0;
                else return INT_MIN;
            case '>':
                if(left->equal()> right->equal()) return 0;
                else return INT_MIN;
            case '#':
                if(left->equal()>= right->equal()) return 0;
                else return INT_MIN;
            case '$':
                if(left->equal()<= right->equal()) return 0;
                else return INT_MIN;
            case ',':
                a= left->equal();
                b= right->equal();
                if(a==b) {
                    return 0;
                }
                else return INT_MIN;
            case '[':
                a= left->equal();
                b= right->equal();
                if(a==INT_MIN || b==INT_MIN) return INT_MIN;
                else if(a!=b) return 0;
                else return INT_MIN;
            case '&':
                a= left->equal();
                b= right->equal();
                if(a!=INT_MIN&&b!=INT_MIN) return 0;
                else return INT_MIN;
            case '|':
                a= left->equal();
                b= right->equal();
                if((a!=INT_MIN)||b!=INT_MIN) return 0;
                else return INT_MIN;
            default:
                return NULL;
        }
    }
};

////VARIABLE
class Variable : public Phrase {
public:
    Variable(char *n){
        name=new String(n);
    }
    virtual int equal() {
        if(mem.find(*name)!=NULL) {
            return mem.find(*name)->value;
        }
        else {

            mem.add(name->name);
            return mem.find(*name)->value;
        }

    }

    String *name;
};
//////////////////////COMMANDS//////////////////////////////////////

////PARENT
class Command{
public:
    virtual void equalCom() = 0;
};

///ASSIGN
class Assign : public Command{
    String *var;
    Phrase *expr;
public:
    Assign(char *v, Phrase *e){
        var = new String(v);
        expr=e;
    }
    virtual void equalCom(){
        count++;
        if(count>ogranicznik){
            std::cout<<count-1<<std::endl;
            mem.read();
            exit(0);
        }
        if(mem.find(var->name)!=NULL) {
            mem.find(var->name)->value = expr->equal();
        }
        else {

            mem.add(var->name);
            mem.find(var->name)->value = expr->equal();
        }
    }
};

///EXPRESSIONN
class Expr:public Command{
    Phrase *e;

public:
    Expr(Phrase *e) :e(e){};

    virtual void equalCom(){
        e->equal();
    }
};

////COMPOSITION
class Composition : public Command{
    Command *left, *right;

public:

    Composition(Command *l, Command *r) : left(l), right(r){};

    virtual void equalCom()
    {
        left->equalCom();
        right->equalCom();
    }
};

////IF
class If : public Command
{
    Command* branch_then;
    Phrase* condition;

public:
    If(Phrase* c, Command* t)
            : condition(c), branch_then(t){ }
    virtual void equalCom()
    {
        count++;
        if(count>ogranicznik){
            std::cout<<count-1<<std::endl;
            mem.read();
            exit(0);
        }
        if (condition->equal() !=INT_MIN) {
            branch_then->equalCom();
        }
    }
};


///WHILE
class While : public Command
{
    Command *body;
    Phrase* condition;

public:
    While(Phrase* c, Command* b)
            : condition(c), body(b) { }
    virtual void equalCom()
    {
        count++;
        if(count>ogranicznik){
            std::cout<<count-1<<std::endl;
            mem.read();
            exit(0);
        }
        while(condition->equal() !=INT_MIN)
        {
            count++;
            body->equalCom();
        }
    }
};

//////////////////////PARSER////////////////////////////////////////
class Parser{
    String input;
    size_t position;

public:
    Parser(String input) : input(input), position(0) {
        input.add(EOS);
        parProgram();
    }

    void skip_whitespace(){
        while(isspace(input[position]))
            position++;
    }
    char look_ahead(){
        skip_whitespace();
        return input[position];
    }

    ///PARSE EXPRESSION
    Phrase* parExpression(){
        Phrase *e = parLogic();
        if(look_ahead()==EOS)
            return e;
        else{
            delete e;
            return NULL;
        }

    }

    ///PARSE & and |
    Phrase* parLogic(){
        Phrase *e= parCheckers();
        char c=look_ahead();
        while(c=='&' || c=='|'){
            position++;
            e=new Operator(c,e, parCheckers());
            c=look_ahead();
        }
        return e;
    }
    ///PARSE != and ==
    Phrase* parCheckers(){
        Phrase *e= parOomparator();
        char c=look_ahead();
        while(c=='!' || c=='='){
            position++;
            if(input[position]=='='){
                if(c=='!') c='[';
                else if(c=='=') c=',';
                position++;
                e=new Operator(c,e, parOomparator());
                c=look_ahead();
            }
        }
        return e;
    }
    ///PARSE > , <, >=, <=
    Phrase* parOomparator(){
        Phrase *e = parSum();
        char c=look_ahead();
        while(c=='>' || c=='<'){
            position++;
            if(input[position]=='='){
                if(c=='>') c='#';
                else if(c=='<') c='$';
                position++;
            }
            e=new Operator(c,e, parSum());
            c=look_ahead();
        }
        return e;
    }
    ///PARSE + and -
    Phrase* parSum() {
        Phrase *e = parMult();
        char c=look_ahead();
        while(c=='+' || c=='-'){
            position++;
            e=new Operator(c,e, parMult());
            c=look_ahead();
        }
        return e;
    }
    ///PARSE *,/ and %
    Phrase* parMult(){
        Phrase *e = parTerm();
        char c = look_ahead();
        while(c=='*' || c == '/' || c=='%'){
            position++;
            e=new Operator(c,e, parTerm());
            c=look_ahead();
        }
        return e;
    }

    Phrase* parTerm(){
        char c=look_ahead();
        if(isdigit(c))
            return parConstant();
        else if(isalpha(c))
            return parVariable();
        else if(c=='(')
            return parParen();
        else if(c=='-')
            return parMinus();
        else if(c=='!'){
            return parNegation();
        }

        else return NULL;
    }
    Phrase* parConstant(){
        int n=0;
        while(isdigit(input[position])){
            n*=10;
            n+=input[position]-'0';
            position++;
        }
        return new Constant(n);
    }
    Phrase* parVariable(){
        String s;
        while(isalnum(input[position])){
            s.add(input[position]);
            position++;
        }
        if(input[position]=='=' && input[position+1]!='='){
            position++;
            Phrase* e = parLogic();
            count++;
            if(count>ogranicznik){
                std::cout<<count-1<<std::endl;
                mem.read();
                exit(0);
            }
            if(mem.find(s.name)!=NULL) {
                mem.find(s.name)->value = e->equal();
            }
            else {

                count++;
                if(count>ogranicznik){
                    std::cout<<count-1<<std::endl;
                    mem.read();
                    exit(0);
                }
                mem.add(s.name);
                mem.find(s.name)->value = e->equal();
            }

        }
        return new Variable(s.name);
    }
    Phrase* parParen(){
        position++;
        Phrase *e= parLogic();
        if(look_ahead()==')'){
            position++;
            return e;
        }
        else return NULL;
    }
    Phrase *parMinus(){
        Phrase*e;
        position++;
        if(input[position]=='(') {
            e = parParen();
            return new Constant(-(e->equal()));
        }
        else if(isalpha(input[position])) {
            e = parVariable();
            count++;
            return new Constant(-(e->equal()));
        }
        else if(isdigit(input[position])) {
            e = parConstant();
            return new Constant(-(e->equal()));
        }
        else {
            e = parLogic();
            return new Constant(-(e->equal()));
        }
    }
    Phrase *parNegation(){
        if(neg)
            neg=false;
        else if(!neg)
            neg=true;
        Phrase*e;
        position++;
        count++;
        if(input[position]=='(')
            e= parParen();
        else if(isalpha(input[position]))
            e= parVariable();
        else if(isdigit(input[position]))
            e= parConstant();
        else if(input[position]=='!'){
            e= parNegation();
        }
        else e= parLogic();

        if(neg && e->equal() != INT_MIN) {
            // counter+=map.counter;
            neg=false;
            return new Constant(INT_MIN);
        }
        else if(neg) {
            neg=false;
            return new Constant(0);
        }
        else return new Constant(0);
    }


    String parIdentifier()
    {
        String s;
        while (isalnum(input[position]))
        {
            s.add(input[position]);
            position++;
        }
        return s;
    }

    Command* parProgram(){
        Command* p = parBlock();
        if (look_ahead() == EOS) {
            p->equalCom();
            return p;
        }
        else{
            delete p;
            return NULL;
        }
    }
    Command* parBlock(){
        Command* p = parInstruction();

        char c = look_ahead();
        while(c != '}' && c != EOS)
        {
            Command* q = parInstruction();
            p = new Composition(p, q);
            c = look_ahead();
        }

        return p;
    }
    Command* parsParen(){
        Command* p = parInstruction();

        char c = look_ahead();
        while(c != ')')
        {
            Command* q = parInstruction();
            p = new Composition(p, q);
            c = look_ahead();
        }

        return p;
    }
    Command* parInstruction(){
        char c = look_ahead();
        if(c=='{'){
            position++;
            Command *p = parBlock();
            if(look_ahead()=='}'){
                position++;
                return p;
            }
        }
        else if(c=='('){
            position++;
            Command *p = parsParen();
            if(look_ahead()==')'){
                position++;
                return p;
            }
        }
        else if(c=='?'){
            return parIf();
        }
        else if(c=='@'){
            return parWhile();
        }
        else if(isalpha(c)){
            String s= parIdentifier();
            return parAssign(s);
        }
        else if(isdigit(c))
            return parExpr();
        return NULL;
    }
    Command* parIf() {
        position++;
        Phrase *e = parParen();
        Command *p = parInstruction();
        return new If(e, p);
    }
    Command *parExpr(){
        Phrase*e = parLogic();
        return new Expr(e);
    }

    Command* parWhile(){
        position++;
        Phrase* e = parParen();
        Command* p = parInstruction();
        return new While(e, p);
    }
    Command* parAssign(String v){
        char c = look_ahead();
        if (c == '=')
        {
            position++;
            Phrase* e = parLogic();
            return new Assign(v.name, e);
        }
        return NULL;
    }

};

/////////////////////////MAIN////////////////////////////////////////
int main() {
///Calculator for checking expressions:
//        String input;
//
//    Memory m;
//    while(true) {
//        std::cin >> input;
//        Parser parser(input,m);
//        Phrase *e = parser.parse_Expression();
//        int x=e->equal(m);
//        std::cout<<m.counter<<std::endl;
//        std::cout<<x<<std::endl;
//
//        input.clean();
//    }
    ///Script language
    count=0;
    String global,command;
    std::cin>>ogranicznik;
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin>>global;
    mem.convertToVariables(global);
    while(!std::cin.eof()){
        std::cin>>command;
        Parser parser(command);
        std::cout<<count<<std::endl;
        mem.read();
        command.clean();

    }

    return 0;
}