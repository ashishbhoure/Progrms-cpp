//Program to implement binary tree

#include <iostream>
using namespace std;

struct node {
   node *l, *r;
   int d;
}*r = NULL, *p = NULL, *np = NULL, *q;

void create() {
   int v,c = 0;
   while (c < 6) {
      if (r == NULL) {
         r = new node;
         cout<<"enter value of root node\n";
         cin>>r->d;
         r->r = NULL;
         r->l = NULL;
      } else {
         p = r;
         cout<<"enter value of node\n";
         cin>>v;
         while(true) {
            if (v< p->d) {
               if (p->l == NULL) {
                  p->l = new node;
                  p = p->l;
                  p->d = v;
                  p->l = NULL;
                  p->r = NULL;
                  cout<<"value entered in left\n";
                  break;
               } else if (p->l != NULL) {
                  p = p->l;
               }
            } else if (v >p->d) {
               if (p->r == NULL) {
                  p->r = new node;
                  p = p->r;
                  p->d = v;
                  p->l = NULL;
                  p->r = NULL;
                  cout<<"value entered in right\n";
                  break;
               } else if (p->r != NULL) {
                  p = p->r;
               }
            }
         }
      }
      c++;
   }
}
