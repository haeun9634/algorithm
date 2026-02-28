-- 코드를 입력하세요
 SELECT member_name, review_text, date_format(review_date,'%Y-%m-%d') from rest_review r join member_profile m on m.member_id = r.member_id where r.member_id = (select rr.member_id from rest_review as rr group by rr.member_id order by count(*) desc limit 1) order by review_date asc, review_text asc

