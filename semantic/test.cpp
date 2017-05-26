#include <bits/stdc++.h>

using namespace std;

int f()
{
	return 11;
}


int main()
{
	int f=5;
	cout<<f();
}



int find_func_in_table(invo_val *in,int *re_type)
{
	symbol_table *p =cur_table;

	while(p!=NULL)
	{
		symbol_list* list = p->s_list;
		while(list!=NULL)
		{
			if(strcmp(list->name,in->name)==0)
			{
				id_val* pr = (id_val*)list->val;
				*re_type = pr->type;
				if(pr->kind!=KIND_FUNCTION)
					return ERROR_ID_KIND;
				else
				{
					// check argu;
					func_val* funcp= (func_val*)pr->list;

					if(funcp->argc != in->listc )
						return ERROR_FUNC_ARGU_NOT_MATCH;
					else
					{
						for(int t=0;t<funcp->argc;t++)
						{
							const_val *constp = ((const_val*)in->listv)+t;
							argu_val *argup = ((argu_val*)funcp->argv)+t;

							invo_val* source=(invo_val*)constp->value;
							arr_val* arr_source= count_arr_ref(source->name);
							arr_val* arr_func =  ((arr_val*)((id_val*)argup->val)->list);
							
							if(arr_func->stepc == source->listc)
							{
								for(int i1=0,i2=arr_source->stepc-source->listc;i1<arr_func->stepc;i1++,i2++)
								{
									if( arr_func->stepv[i1] != *(((int*)arr_source->stepv)+i2) )
										return ERROR_FUNC_ARGU_NOT_MATCH;
								}
							}
							else
								return ERROR_FUNC_ARGU_NOT_MATCH;
						}
						return NO_ERROR;
					}
				}
			}
			list=list->next;
		}
		p=p->next;
	}
	*re_type=TYPE_INT;
	return ERROR_ID_NO_FOUND;
}


int find_arr_in_table(invo_val *in, int *re_type)
{
	symbol_table *table = cur_table;
	while(table!=NULL)
	{
		symbol_list *list= table->s_list;
		while(list!=NULL)
		{
			if(strcmp(in->name,list->name)==0)
			{
				id_val *pr=(id_val*)list->val;
				*re_type = pr->type;


				if(pr->kind != KIND_VARIABLE && pr->kind != KIND_PARAMETER && pr->kind!=KIND_CONSTANT)
					return ERROR_ID_KIND;
				else
				{

					if(pr->kind==KIND_CONSTANT && in->listc!=0)
					{
						if(in->listc!=0)
							return ERROR_ARR_STEP;
						else
							return NO_ERROR;
					}
					arr_val* arr_step=(arr_val*)pr->list;
					if(in->listc > arr_step->stepc)
						return ERROR_ARR_STEP;
					else
						in->listc = arr_step->stepc - in->listc;
				}
				return NO_ERROR;
			}
			list= list->next;
		}
		table=table->next;
	}
	*re_type=TYPE_INT;
	return ERROR_ID_NO_FOUND;
}
