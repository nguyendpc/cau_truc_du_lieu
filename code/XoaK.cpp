void xoaK(Node *&dau, int k)
 {
	if(dau!=NULL)
	{
		if(k==0){
			Node *p; 
			p= dau;
			dau = p->tiep;
			delete p;
		}
		else 
		{
			int dem = 0;
			Node *p, *q;
			p = dau;
			while (dem < k)
			{
				q=p;
				p=p->tiep;
				dem++;
			}
			q->tiep = p->tiep;
			delete p;
		}
	}
}
