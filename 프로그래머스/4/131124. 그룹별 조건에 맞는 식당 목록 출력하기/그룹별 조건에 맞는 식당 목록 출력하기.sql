# -- 코드를 입력하세요
 SELECT member_name, review_text, date_format(review_date,'%Y-%m-%d') from member_profile mp join rest_review rr on mp.member_id = rr.member_id where rr.member_id in (select member_id from rest_review group by member_id having count(*) = (select count(*) from rest_review group by member_id order by count(*) desc limit 1 )) order by review_date, review_text
 

