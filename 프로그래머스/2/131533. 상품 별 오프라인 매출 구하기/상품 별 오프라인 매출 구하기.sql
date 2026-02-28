-- 코드를 입력하세요

select product_code, (sum(sales_amount) * price) as sales from product as p join offline_sale as o on p.product_id = o.product_id group by p.product_id order by sales desc, product_code asc 


-- SELECT product_code, (select sum(sales_amount) * price from product as p join offline_sale as o on p.product_id = o.product_id group by p.product_id) as sales from product order by sales desc, product_code asc 