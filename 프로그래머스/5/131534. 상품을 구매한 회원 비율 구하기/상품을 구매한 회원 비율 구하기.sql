-- 코드를 입력하세요

select year(sales_date) YEAR, month(sales_date) month, count(distinct ui.user_id) purchased_users, round(count(distinct ui.user_id)/(select count(distinct uii.user_id) from user_info uii where year(uii.joined) = 2021),1) puchased_ratio
from user_info ui join online_sale os on ui.user_id = os.user_id 
where year(joined) = 2021 
group by year, month
order by year, month;

