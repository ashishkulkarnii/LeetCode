select T.name as customers from (select customers.name, orders.customerid from customers left join orders on orders.customerid = customers.id) as T where T.customerid is null