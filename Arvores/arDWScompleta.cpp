#include <queue>
#include <iostream>

using namespace std;


template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left,*right;
		ArvoreNo(){
			left=right=0;			
		}
		ArvoreNo(T e,ArvoreNo<T> *l=0,ArvoreNo<T> *r=0){
			el=e;
			left=l;
			right=r;
		}
};

template<class T>
class Arvore {
	protected:
		ArvoreNo<T> *root;
	public:
		Arvore(){
			root = 0;			
		}
		~Arvore(){
			clear();
		}
		void clear(){
			clear(root);
			root=0;
		}
		
		ArvoreNo<T>* getRoot(){
			return root;
		}
		bool isEmpty() const {
		   return root=0;
		   }
		   
		void visit(ArvoreNo<T> *p){
			cout<<p->el<<" ";
		} 
		
		T search(T el) {
			ArvoreNo<T> *p=root;
			while (p!=0){
				
				if (el==p->el)		
					return p->el;								    
				else{					
					if (el < p->el)
				       p=p->left;
				   else p=p->right;
			 	}
		    }
			return 0;			
			
		}
		 //obs: pg 209 figura 6.23
		void insert(T el){
			ArvoreNo<T> *p = root, *prev = nullptr;
            while (p != nullptr) {
                prev = p;
                if (el < p->el)
                    p = p->left;
                else
                    p = p->right;
            }
            if (root == nullptr) {
                root = new ArvoreNo<T>(el);
            } else if (el < prev->el) {
                prev->left = new ArvoreNo<T>(el);
            } else {
                prev->right = new ArvoreNo<T>(el);
            }
    
    backbone(root); // Chama o backbone para balancear a árvore após a inserção
		
		void percusoExtensao(){
			queue<ArvoreNo<T>*> f;
			ArvoreNo<T> *p=root;
			if (p!=NULL){
				f.push(p);
				while (!f.empty()){
					p=f.front();					
					visit(p);
					f.pop();
					if (p->left!=0)
						f.push(p->left);
					if (p->right!=0)
						f.push(p->right);
				}	}
		}
		
		
		void preorder(ArvoreNo<T> *p){
			if (p!=0) {
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}
			
		}
		
			
        void backbone(ArvoreNo<T> *p){
            ArvoreNo<T> *prev = nullptr;
            while (p != nullptr) {
                if (p->left != nullptr) {
                    // Rotação à direita
                    ArvoreNo<T> *q = p->left;
                    p->left = q->right;
                    q->right = p;
                    p = q;
                    if (prev == nullptr) {
                        root = p;
                    } else {
                        prev->right = p;
                    }
                } else {
                    prev = p;
                    p = p->right;
                }
            }			
        }
	};
	
	
main(){
	
	Arvore<int> *a=new Arvore<int>();

	a->insert(20);
	
	
	a->preorder(a->getRoot());

		
	
	
	cout<<"---Apos as rotacoes -----"<<endl;
	a->preorder(a->getRoot());
	


	

	
   	
   	
}
