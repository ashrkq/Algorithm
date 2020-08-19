#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 临接表使用数组实现的方式
struct Edge{
    int u,v,w;
    int next;
}edge[100010];
int head[10010];
int num;
void build_edge(int u,int v,int w){
    edge[num].u = u; edge[num].v = v; edge[num].w = w;
    edge[num].next = head[u];
    head[u] = num++;
}
void quir(int u){
    for (int i = head[u]; i!=-1; i = edge[i].next)
        printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
}
void init(){
    num = 0;
    memset(head, 0xff, sizeof(head));
}


// 这里是写一个指针的实现方式
struct Node{
    int u,v,w;
    Node *next;
}*node[10010];

void init2(){
    memset(node, 0, sizeof(node));
}
void add_node(int u,int v,int w){
    Node *p = (Node *)malloc(sizeof(Node));
    p->u = u; p->v = v; p->w = w;
    p->next = node[u];
    node[u] = p;
}
void pr_node(int u){
    for(Node *i = node[u];i;i = i->next){
        printf("%d %d %d\n",i->u,i->v,i->w);
    }
}
int main(){
    init();
//    for(int i=1;i<=10;i++) printf("%d\n",first[i]);
//    for(int i=0;i<5;i++){
//        int u,v,w;
//        scanf("%d %d %d",&u,&v,&w);
//        build_edge(u, v, w);
//        build_edge(v, u, w);
//    }
//    printf("~~~~~~~~~~\n");
//    quir(1);
//    printf("~~~~~~~~~~\n");
//    quir(5);
    init2();
    for(int i=0;i<5;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add_node(u, v, w);
        add_node(v, u, w);
    }
    printf("qwqweqweqwe\n");
    pr_node(1);
    printf("~~～～～～～～～～\n");
    pr_node(5);
    return 0;
}
