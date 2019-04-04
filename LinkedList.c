int ll_find_by_value(llnode *pList, int val) {
    if (pList==NULL){
       return -1;
    }
    if (pList->next==NULL){
        if (pList->val==val){
          printf("hey you made it");
          return 0;
 
        }
        else {
            return -1;
 
        }
    }
    else {
        if(pList->val==val){
            printf("hey you are awesome");
            return 0;
        }
 }
 return ll_find_by_value((pList->next),val);
 }
 
 int ll_del_from_tail(llnode **ppList){
     if (ppList==NULL){
         return -1;
     }
     if((*ppList)->next->next==NULL){
         llnode *f = (*ppList)->next->next;
         (*ppList)->next=NULL;
         ll_free(f);
         return 0;
     }
     else {
         return ll_del_from_tail(&((*ppList)->next));
     }
     }
 
 int ll_del_from_head(llnode **ppList){
     llnode *new_head = *ppList;
     if (ppList==NULL){
         return -1;
     }
     free(new_head);
     *ppList= (*ppList)->next;
 
     return 0;
 
 }
 
 int ll_del_by_value(llnode **ppList,int val){
     if (ppList==NULL){
         return -1;
     }

    if ((*ppList)->val==val){
         free (*ppList);
         (*ppList)=(*ppList)->next;
         return 0;
         }
     else if(((*ppList)->next->next==NULL) && (((*ppList)->next)->val==val)){
 
 
         free((*ppList)->next);
         (*ppList)->next=NULL;
 
 
         return 0;
     }
     else if(((*ppList)->next)->val==val){
             llnode *new= (*ppList)->next->next;
 
             free((*ppList)->next);
             (*ppList)->next= new;
             return 0;
         }
     else{
         return ll_del_by_value(&((*ppList)->next),val);
         }
 }
 
 int ll_insert_in_order(llnode **ppList,int val) {
        /* we are going to iterate through the linked list to find the
         *       insertion point; we will need to track the prior node so we
         *             can stitch in the new node properly
         *                   -> thus we will create two pointers to track the nodes
         *                            "curr" and "prev"
         *                               */
    llnode *prev = NULL;
    llnode *curr = NULL;
 
    if (ppList == NULL) { return -1; }
    if (*ppList == NULL) {
     /* if we're dealing with an empty linked list, just call
      *          add to head */
        return ll_add_to_head(ppList,val);
                              }
 /* otherwise: we iterate through the list until will find the         *       insert location */
 /* first we handle the degenerate case of the first node */
     if ((*ppList) -> val > val) {
       return ll_add_to_head(ppList,val);
      }
     else {
         prev = *ppList;
         curr = (*ppList)->next;
         while(curr != NULL) {
           if (curr->val > val) {
                break;
           }
           else {
                    prev = curr;
                    curr = prev->next;
                 }
                             }
         prev->next = (llnode *) malloc(sizeof(llnode));
         prev->next->val  = val;
         prev->next->next = curr;
         return 0;
                    }
 }
 
 int ll_concat(llnode **pSrcA, llnode **pSrcB){
     llnode *P;
     P=*pSrcA;
     if ((pSrcA==NULL)&& (pSrcB==NULL)){
     return -1;
     }
     if(*pSrcA==NULL){
        P=*pSrcB;
        return 0;
     }
     else if(*pSrcB==NULL){
        P=*pSrcA;
        return 0;
     }
     else{
        P=*pSrcA;
        while(P->next!=NULL){
            P=P->next;
        }
         P->next= *pSrcB;
        /* while ((*pSrcB)->next!=NULL){
             *pSrcB= (*pSrcB)->next;
         }*/
     }
         ll_print(*pSrcA);
         return 0;
 }
 
 int ll_sort(llnode **ppList){
     llnode *i;
     llnode *j;
     int temp;
     if(ppList==NULL){
         return -1;
     }
 
    /* llnode *i=*ppList;
     llnode *j=i->next;*/
 
     for(i=*ppList;i->next!=NULL;i=i->next){
         for(j=i->next;j!=NULL;j=j->next){
             if (i->val>j->val){
                 temp = i->val;
                 i->val = j->val;
                 j->val=temp;
             }
         }
     }
     return 0;
 
 
 
 }