# MSSQL charindex 
## syntax
> [!NOTE] 
> CHARINDEX ( expressionToFind , expressionToSearch [, startlocation] )    
 CHARINDEX cannot be used with image, ntext, or text data types.   
 The starting position returned is 1-based, not 0-based.   

> [!NOTE]
> declare @string varchar(10);  
set @string='hello';    
select charindex('l',@string);   
select charindex('l',@string,4);   
select charindex('a',@string);      
select charindex('h',@string);  
select charindex('Ello',@string);   
select charindex('Hello',@string collate latin1_General_CI_AS);     
select charindex('a',@string);     
select charindex('ll',@string);   
select charindex('ello',@string);    
select charindex('hellohi',@string);   
