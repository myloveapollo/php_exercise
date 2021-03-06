--Mysql 指令

SELECT customers.customerid,orders.orderid,orders.amount, orders.DATE
FROM customers, orders
WHERE customers.name = "Julie Smith"
AND customers.customerid = orders.customerid;

SELECT customers.name
FROM customers, orders, order_items,books
WHERE customers.customerid = orders.customerid
AND orders.orderid = order_items.orderid
AND order_items.isbn = books.isbn
AND books.title LIKE "Java%";

SELECT c.name
FROM customers AS c, orders AS o, order_items AS oi, books AS b
WHERE c.customerid = o.customerid
AND o.orderid = oi.orderid
AND oi.isbn = b.isbn
AND b.title LIKE "Java%";

SELECT customers.customerid, customers.name, orders.orderid
FROM customers 
LEFT JOIN orders
ON customers.customerid = orders.customerid;

SELECT customers.customerid, customers.name
FROM customers 
LEFT JOIN orders
using (customerid)
WHERE orders.orderid IS null;

SELECT name, address
FROM customers
ORDER BY name asc;

SELECT AVG(amount)
FROM orders;

SELECT customerid, AVG(amount)
FROM orders
GROUP BY customerid
HAVING AVG(amount) > 50;

--子查询，嵌套在另一个查询里面的内部查询
SELECT customerid, amount
FROM orders
WHERE amount = (SELECT MAX(amount) FROM orders);

SELECT customerid, amount
FROM orders
ORDER BY amount DESC
limit 1;

SELECT isbn, title
FROM books
WHERE NOT EXISTS
(SELECT * FROM order_items WHERE order_items.isbn = books.isbn);

SELECT * 
FROM (SELECT customerid, name FROM customers WHERE city='Box Hill')
AS box_hill_customers;
--修改数据类型
ALTER TABLE customers
modify name VARCHAR(70) NOT null;

ALTER TABLE orders
ADD tax FLOAT(6,2) after amount;

ALTER table orders
DROP tax;

select * from books where title like '%GIMP%';