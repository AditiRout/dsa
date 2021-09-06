#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<math.h>

#define SIZE 50 /* Size of s */

double s[SIZE];
int oprtr_top = -1;
int oprtr[SIZE];

int top=-1;            /* Global declarations */
int flag=0;
double pop()
{                      /* Function for POP operation */
  return(s[top--]);
}

void push1(double elem)
{                     /* Function for postPUSH operation */
  if(flag==1){
    double num;
    num=pop();
    s[++top]=elem+10*num;
  }
  else if(flag==0){
    s[++top]=elem;
    flag=1;
  }
}


void evalpost(char exp[])
   {
    int i=0;
    double op2,op1;
    char ch;
    while((ch=exp[i])!='\n'){
        if(isdigit(exp[i]))push1(ch-'0');
        else if (ch==' ') flag=0;
        else {
            flag=0;
            op2=pop();
            op1=pop();
            switch(exp[i]){
                case '+':push1(op1+op2);break;
                case '-':push1(op1-op2);break;
                case '*':push1(op1*op2);break;
                case '/':push1(op1/op2);break;
                case '^':push1(pow(op1,op2));break;
                default:
                 printf("Input invalid ... give proper input\n");


            }

        }
        i++;
    }
    double z=pop();
    printf("Answer is:%f\n",z);
}

void push2(double elem)
{ /* Function for PUSH operation */
  if(flag==1){
    double num;
    num=pop();
    s[++top]=num+10*elem;
  }
  else if(flag==0){
    s[++top]=elem;
    flag=1;
  }
}

void evalpre(char exp[]){
  double op1,op2;
  char ch;
  int i = strlen(exp) - 1;
  while(i--)
  {
    ch = exp[i];
    if(isdigit(ch)) push2(ch-'0');        /* Push the operand */
    else if(ch==' ')
      flag=0;
    else
    {                                     /* Operator,pop two  operands */
      flag=0;
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':push2(op1+op2);break;
        case '-':push2(op2-op1);break;
        case '*':push2(op1*op2);break;
        case '/':push2(op2/op1);break;
        case '^':push2(pow(op2,op1));break;
        default:
                 printf("Input invalid ... give proper input\n");

      }
    }
  }
  double z=pop();
  printf("Result: %f\n",z);
}

int isoperator(char c){

      switch(c){

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                  return 1;
            default:
                  return 0;

      }
}


int prec(char c){

      switch(c){

            case '^':
                  return 3;
            case '*':
            case '/':
                  return 2;
            case '+':
            case '-':
                  return 1;
            default:
                  return 0;

      }
}

void push(double val) {

      if( top == SIZE - 1)
            printf("Overflow\n");
      s[++top] = val;
}

void push_oprtr(char c) {
      if(oprtr_top == SIZE - 1){
        printf("s Overflow\n");
        return;
      }
      oprtr[++oprtr_top] = c;
}

char pop_oprtr() {
      if(oprtr_top == -1){
            printf("s Underflow\n");
            return  0;
      }
      return oprtr[oprtr_top--];
}

void operation(double a, double b, char oprtr) {

      if( oprtr == '+')
            push(a + b);
      else if( oprtr == '-')
            push(a - b);
      else if( oprtr == '*')
            push(a * b);
      else if( oprtr == '/')
            push( a / b);
      else if(oprtr=='^')push(pow(a,b));
}

int evalInfix(char infix[]) {

      push_oprtr('(');
      int val=0;
      int i=0;
      double data=0;
      int g=0;
      char ch;

      while( infix[i] != '\0') {
            i++;
      }
      infix[i] = ')';
      infix[i+1] = '\0';
      i = 0;
      while( infix[i] != '\0'){

            double oprnd1;
            double oprnd2;
            char oprtr;
            ch = infix[i];
            if(isdigit(ch))                   //for more than one digit numbers
            {
                  data=data*10+(ch-48);
                  g=1;
                  i++;
                  continue;
            }
            if(g){
                  push(data);
                  g=0;
                  data=0;
            }
            if(ch=='('){
                  push_oprtr(ch);
            }
            else if(ch==')'){

                  oprtr = pop_oprtr();
                  while(oprtr != '('){
                        oprnd1 = pop();
                        oprnd2 = pop();
                        operation(oprnd2, oprnd1,oprtr);
                        oprtr = pop_oprtr();
                  }
            }
            else if(isoperator(ch)){

                  oprtr = pop_oprtr();
                  while( isoperator(oprtr) && prec(oprtr) >= prec(ch)){
                        oprnd1 = pop();
                        oprnd2 = pop();
                        operation(oprnd2, oprnd1,oprtr);
                        oprtr = pop_oprtr();
                  }
                  push_oprtr(oprtr);
                  push_oprtr(ch);
            }
            i++;
      }
      double z = pop();
      printf("Answer is %f\n",z);
}

int main()
{                         /* Main Program */
  char exp[50];
  int c=-1;
  while(c!=4){
        top=-1;
        flag=0;
        printf("\t|| Menu ||\n1. Prefix evaluation\n");
        printf("2. Infix evaluation\n3. Postfix evaluation\n");
        printf("4. Exit\nPlease choose an option: ");
        scanf("%d", &c);
        getchar(); // get rid of annoying endline
        switch(c) {
             case 1 :
                 printf("Please enter input separated by a space between each number and operator.");
                 printf("\nEnter the Prefix Expression:");
                 fgets(exp,100,stdin);
                 evalpre(exp);
                 break;
             case 2:
                 printf("Please enter input separated by a space between each number and operator.");
                 printf("\nEnter the Infix Expression:");
                 fgets(exp,100,stdin);
                 evalInfix(exp);
                 break;

             case 3:
                 printf("Please enter input separated by a space between each number and operator.");
                 printf("\nEnter the Postfix Expression:");
                 fgets(exp,100,stdin);
                 evalpost(exp);
                 break;
            case 4: printf("Thank you for using this program.\n");
                    break;
            default: printf("Invalid input. Please choose from the given options.\n\n");
        }
  }
  return 0;
}
