#include "stdafx.h"


vector<string> split(string s,string delimiter)
{
	vector<string> v;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0,pos);
		v.push_back(token);
		s.erase(0,pos + delimiter.length());
	}
	if (s.size() > 0) v.push_back(s);
	return v;
}


//string hand_order = "2d2c 2h2c 2h2d 2s2c 2s2d 2s2h 3c2c 3c2d 3c2h 3c2s 3d2c 3d2d 3d2h 3d2s 3d3c 3h2c 3h2d 3h2h 3h2s 3h3c 3h3d 3s2c 3s2d 3s2h 3s2s 3s3c 3s3d 3s3h 4c2c 4c2d 4c2h 4c2s 4c3c 4c3d 4c3h 4c3s 4d2c 4d2d 4d2h 4d2s 4d3c 4d3d 4d3h 4d3s 4d4c 4h2c 4h2d 4h2h 4h2s 4h3c 4h3d 4h3h 4h3s 4h4c 4h4d 4s2c 4s2d 4s2h 4s2s 4s3c 4s3d 4s3h 4s3s 4s4c 4s4d 4s4h 5c2c 5c2d 5c2h 5c2s 5c3c 5c3d 5c3h 5c3s 5c4c 5c4d 5c4h 5c4s 5d2c 5d2d 5d2h 5d2s 5d3c 5d3d 5d3h 5d3s 5d4c 5d4d 5d4h 5d4s 5d5c 5h2c 5h2d 5h2h 5h2s 5h3c 5h3d 5h3h 5h3s 5h4c 5h4d 5h4h 5h4s 5h5c 5h5d 5s2c 5s2d 5s2h 5s2s 5s3c 5s3d 5s3h 5s3s 5s4c 5s4d 5s4h 5s4s 5s5c 5s5d 5s5h 6c2c 6c2d 6c2h 6c2s 6c3c 6c3d 6c3h 6c3s 6c4c 6c4d 6c4h 6c4s 6c5c 6c5d 6c5h 6c5s 6d2c 6d2d 6d2h 6d2s 6d3c 6d3d 6d3h 6d3s 6d4c 6d4d 6d4h 6d4s 6d5c 6d5d 6d5h 6d5s 6d6c 6h2c 6h2d 6h2h 6h2s 6h3c 6h3d 6h3h 6h3s 6h4c 6h4d 6h4h 6h4s 6h5c 6h5d 6h5h 6h5s 6h6c 6h6d 6s2c 6s2d 6s2h 6s2s 6s3c 6s3d 6s3h 6s3s 6s4c 6s4d 6s4h 6s4s 6s5c 6s5d 6s5h 6s5s 6s6c 6s6d 6s6h 7c2c 7c2d 7c2h 7c2s 7c3c 7c3d 7c3h 7c3s 7c4c 7c4d 7c4h 7c4s 7c5c 7c5d 7c5h 7c5s 7c6c 7c6d 7c6h 7c6s 7d2c 7d2d 7d2h 7d2s 7d3c 7d3d 7d3h 7d3s 7d4c 7d4d 7d4h 7d4s 7d5c 7d5d 7d5h 7d5s 7d6c 7d6d 7d6h 7d6s 7d7c 7h2c 7h2d 7h2h 7h2s 7h3c 7h3d 7h3h 7h3s 7h4c 7h4d 7h4h 7h4s 7h5c 7h5d 7h5h 7h5s 7h6c 7h6d 7h6h 7h6s 7h7c 7h7d 7s2c 7s2d 7s2h 7s2s 7s3c 7s3d 7s3h 7s3s 7s4c 7s4d 7s4h 7s4s 7s5c 7s5d 7s5h 7s5s 7s6c 7s6d 7s6h 7s6s 7s7c 7s7d 7s7h 8c2c 8c2d 8c2h 8c2s 8c3c 8c3d 8c3h 8c3s 8c4c 8c4d 8c4h 8c4s 8c5c 8c5d 8c5h 8c5s 8c6c 8c6d 8c6h 8c6s 8c7c 8c7d 8c7h 8c7s 8d2c 8d2d 8d2h 8d2s 8d3c 8d3d 8d3h 8d3s 8d4c 8d4d 8d4h 8d4s 8d5c 8d5d 8d5h 8d5s 8d6c 8d6d 8d6h 8d6s 8d7c 8d7d 8d7h 8d7s 8d8c 8h2c 8h2d 8h2h 8h2s 8h3c 8h3d 8h3h 8h3s 8h4c 8h4d 8h4h 8h4s 8h5c 8h5d 8h5h 8h5s 8h6c 8h6d 8h6h 8h6s 8h7c 8h7d 8h7h 8h7s 8h8c 8h8d 8s2c 8s2d 8s2h 8s2s 8s3c 8s3d 8s3h 8s3s 8s4c 8s4d 8s4h 8s4s 8s5c 8s5d 8s5h 8s5s 8s6c 8s6d 8s6h 8s6s 8s7c 8s7d 8s7h 8s7s 8s8c 8s8d 8s8h 9c2c 9c2d 9c2h 9c2s 9c3c 9c3d 9c3h 9c3s 9c4c 9c4d 9c4h 9c4s 9c5c 9c5d 9c5h 9c5s 9c6c 9c6d 9c6h 9c6s 9c7c 9c7d 9c7h 9c7s 9c8c 9c8d 9c8h 9c8s 9d2c 9d2d 9d2h 9d2s 9d3c 9d3d 9d3h 9d3s 9d4c 9d4d 9d4h 9d4s 9d5c 9d5d 9d5h 9d5s 9d6c 9d6d 9d6h 9d6s 9d7c 9d7d 9d7h 9d7s 9d8c 9d8d 9d8h 9d8s 9d9c 9h2c 9h2d 9h2h 9h2s 9h3c 9h3d 9h3h 9h3s 9h4c 9h4d 9h4h 9h4s 9h5c 9h5d 9h5h 9h5s 9h6c 9h6d 9h6h 9h6s 9h7c 9h7d 9h7h 9h7s 9h8c 9h8d 9h8h 9h8s 9h9c 9h9d 9s2c 9s2d 9s2h 9s2s 9s3c 9s3d 9s3h 9s3s 9s4c 9s4d 9s4h 9s4s 9s5c 9s5d 9s5h 9s5s 9s6c 9s6d 9s6h 9s6s 9s7c 9s7d 9s7h 9s7s 9s8c 9s8d 9s8h 9s8s 9s9c 9s9d 9s9h Tc2c Tc2d Tc2h Tc2s Tc3c Tc3d Tc3h Tc3s Tc4c Tc4d Tc4h Tc4s Tc5c Tc5d Tc5h Tc5s Tc6c Tc6d Tc6h Tc6s Tc7c Tc7d Tc7h Tc7s Tc8c Tc8d Tc8h Tc8s Tc9c Tc9d Tc9h Tc9s Td2c Td2d Td2h Td2s Td3c Td3d Td3h Td3s Td4c Td4d Td4h Td4s Td5c Td5d Td5h Td5s Td6c Td6d Td6h Td6s Td7c Td7d Td7h Td7s Td8c Td8d Td8h Td8s Td9c Td9d Td9h Td9s TdTc Th2c Th2d Th2h Th2s Th3c Th3d Th3h Th3s Th4c Th4d Th4h Th4s Th5c Th5d Th5h Th5s Th6c Th6d Th6h Th6s Th7c Th7d Th7h Th7s Th8c Th8d Th8h Th8s Th9c Th9d Th9h Th9s ThTc ThTd Ts2c Ts2d Ts2h Ts2s Ts3c Ts3d Ts3h Ts3s Ts4c Ts4d Ts4h Ts4s Ts5c Ts5d Ts5h Ts5s Ts6c Ts6d Ts6h Ts6s Ts7c Ts7d Ts7h Ts7s Ts8c Ts8d Ts8h Ts8s Ts9c Ts9d Ts9h Ts9s TsTc TsTd TsTh Jc2c Jc2d Jc2h Jc2s Jc3c Jc3d Jc3h Jc3s Jc4c Jc4d Jc4h Jc4s Jc5c Jc5d Jc5h Jc5s Jc6c Jc6d Jc6h Jc6s Jc7c Jc7d Jc7h Jc7s Jc8c Jc8d Jc8h Jc8s Jc9c Jc9d Jc9h Jc9s JcTc JcTd JcTh JcTs Jd2c Jd2d Jd2h Jd2s Jd3c Jd3d Jd3h Jd3s Jd4c Jd4d Jd4h Jd4s Jd5c Jd5d Jd5h Jd5s Jd6c Jd6d Jd6h Jd6s Jd7c Jd7d Jd7h Jd7s Jd8c Jd8d Jd8h Jd8s Jd9c Jd9d Jd9h Jd9s JdTc JdTd JdTh JdTs JdJc Jh2c Jh2d Jh2h Jh2s Jh3c Jh3d Jh3h Jh3s Jh4c Jh4d Jh4h Jh4s Jh5c Jh5d Jh5h Jh5s Jh6c Jh6d Jh6h Jh6s Jh7c Jh7d Jh7h Jh7s Jh8c Jh8d Jh8h Jh8s Jh9c Jh9d Jh9h Jh9s JhTc JhTd JhTh JhTs JhJc JhJd Js2c Js2d Js2h Js2s Js3c Js3d Js3h Js3s Js4c Js4d Js4h Js4s Js5c Js5d Js5h Js5s Js6c Js6d Js6h Js6s Js7c Js7d Js7h Js7s Js8c Js8d Js8h Js8s Js9c Js9d Js9h Js9s JsTc JsTd JsTh JsTs JsJc JsJd JsJh Qc2c Qc2d Qc2h Qc2s Qc3c Qc3d Qc3h Qc3s Qc4c Qc4d Qc4h Qc4s Qc5c Qc5d Qc5h Qc5s Qc6c Qc6d Qc6h Qc6s Qc7c Qc7d Qc7h Qc7s Qc8c Qc8d Qc8h Qc8s Qc9c Qc9d Qc9h Qc9s QcTc QcTd QcTh QcTs QcJc QcJd QcJh QcJs Qd2c Qd2d Qd2h Qd2s Qd3c Qd3d Qd3h Qd3s Qd4c Qd4d Qd4h Qd4s Qd5c Qd5d Qd5h Qd5s Qd6c Qd6d Qd6h Qd6s Qd7c Qd7d Qd7h Qd7s Qd8c Qd8d Qd8h Qd8s Qd9c Qd9d Qd9h Qd9s QdTc QdTd QdTh QdTs QdJc QdJd QdJh QdJs QdQc Qh2c Qh2d Qh2h Qh2s Qh3c Qh3d Qh3h Qh3s Qh4c Qh4d Qh4h Qh4s Qh5c Qh5d Qh5h Qh5s Qh6c Qh6d Qh6h Qh6s Qh7c Qh7d Qh7h Qh7s Qh8c Qh8d Qh8h Qh8s Qh9c Qh9d Qh9h Qh9s QhTc QhTd QhTh QhTs QhJc QhJd QhJh QhJs QhQc QhQd Qs2c Qs2d Qs2h Qs2s Qs3c Qs3d Qs3h Qs3s Qs4c Qs4d Qs4h Qs4s Qs5c Qs5d Qs5h Qs5s Qs6c Qs6d Qs6h Qs6s Qs7c Qs7d Qs7h Qs7s Qs8c Qs8d Qs8h Qs8s Qs9c Qs9d Qs9h Qs9s QsTc QsTd QsTh QsTs QsJc QsJd QsJh QsJs QsQc QsQd QsQh Kc2c Kc2d Kc2h Kc2s Kc3c Kc3d Kc3h Kc3s Kc4c Kc4d Kc4h Kc4s Kc5c Kc5d Kc5h Kc5s Kc6c Kc6d Kc6h Kc6s Kc7c Kc7d Kc7h Kc7s Kc8c Kc8d Kc8h Kc8s Kc9c Kc9d Kc9h Kc9s KcTc KcTd KcTh KcTs KcJc KcJd KcJh KcJs KcQc KcQd KcQh KcQs Kd2c Kd2d Kd2h Kd2s Kd3c Kd3d Kd3h Kd3s Kd4c Kd4d Kd4h Kd4s Kd5c Kd5d Kd5h Kd5s Kd6c Kd6d Kd6h Kd6s Kd7c Kd7d Kd7h Kd7s Kd8c Kd8d Kd8h Kd8s Kd9c Kd9d Kd9h Kd9s KdTc KdTd KdTh KdTs KdJc KdJd KdJh KdJs KdQc KdQd KdQh KdQs KdKc Kh2c Kh2d Kh2h Kh2s Kh3c Kh3d Kh3h Kh3s Kh4c Kh4d Kh4h Kh4s Kh5c Kh5d Kh5h Kh5s Kh6c Kh6d Kh6h Kh6s Kh7c Kh7d Kh7h Kh7s Kh8c Kh8d Kh8h Kh8s Kh9c Kh9d Kh9h Kh9s KhTc KhTd KhTh KhTs KhJc KhJd KhJh KhJs KhQc KhQd KhQh KhQs KhKc KhKd Ks2c Ks2d Ks2h Ks2s Ks3c Ks3d Ks3h Ks3s Ks4c Ks4d Ks4h Ks4s Ks5c Ks5d Ks5h Ks5s Ks6c Ks6d Ks6h Ks6s Ks7c Ks7d Ks7h Ks7s Ks8c Ks8d Ks8h Ks8s Ks9c Ks9d Ks9h Ks9s KsTc KsTd KsTh KsTs KsJc KsJd KsJh KsJs KsQc KsQd KsQh KsQs KsKc KsKd KsKh Ac2c Ac2d Ac2h Ac2s Ac3c Ac3d Ac3h Ac3s Ac4c Ac4d Ac4h Ac4s Ac5c Ac5d Ac5h Ac5s Ac6c Ac6d Ac6h Ac6s Ac7c Ac7d Ac7h Ac7s Ac8c Ac8d Ac8h Ac8s Ac9c Ac9d Ac9h Ac9s AcTc AcTd AcTh AcTs AcJc AcJd AcJh AcJs AcQc AcQd AcQh AcQs AcKc AcKd AcKh AcKs Ad2c Ad2d Ad2h Ad2s Ad3c Ad3d Ad3h Ad3s Ad4c Ad4d Ad4h Ad4s Ad5c Ad5d Ad5h Ad5s Ad6c Ad6d Ad6h Ad6s Ad7c Ad7d Ad7h Ad7s Ad8c Ad8d Ad8h Ad8s Ad9c Ad9d Ad9h Ad9s AdTc AdTd AdTh AdTs AdJc AdJd AdJh AdJs AdQc AdQd AdQh AdQs AdKc AdKd AdKh AdKs AdAc Ah2c Ah2d Ah2h Ah2s Ah3c Ah3d Ah3h Ah3s Ah4c Ah4d Ah4h Ah4s Ah5c Ah5d Ah5h Ah5s Ah6c Ah6d Ah6h Ah6s Ah7c Ah7d Ah7h Ah7s Ah8c Ah8d Ah8h Ah8s Ah9c Ah9d Ah9h Ah9s AhTc AhTd AhTh AhTs AhJc AhJd AhJh AhJs AhQc AhQd AhQh AhQs AhKc AhKd AhKh AhKs AhAc AhAd As2c As2d As2h As2s As3c As3d As3h As3s As4c As4d As4h As4s As5c As5d As5h As5s As6c As6d As6h As6s As7c As7d As7h As7s As8c As8d As8h As8s As9c As9d As9h As9s AsTc AsTd AsTh AsTs AsJc AsJd AsJh AsJs AsQc AsQd AsQh AsQs AsKc AsKd AsKh AsKs AsAc AsAd AsAh";
//string hands_compressed[169] = {"AA","KK","QQ","JJ","TT","AKs","99","AKo","AQs","88","AQo","AJs","77","ATs","AJo","66","ATo","55","A9s","KQs","44","A8s","KJs","A9o","QJs","33","KTs","QTs","A7s","JTs","KQo","KJo","A5s","K9s","22","QJo","A6s","A8o","A4s","KTo","Q9s","J9s","QTo","A3s","T9s","A2s","K8s","JTo","K6s","K7s","Q8s","J8s","A5o","K5s","A7o","T8s","A6o","K9o","98s","K4s","A4o","Q6s","Q9o","Q7s","J7s","J9o","K3s","T9o","97s","T7s","A3o","76s","Q5s","87s","K2s","65s","86s","Q4s","J6s","A2o","96s","K8o","T6s","J5s","54s","K7o","Q3s","K6o","J8o","75s","Q8o","T8o","J4s","98o","Q2s","K5o","85s","64s","J3s","95s","T5s","K4o","T4s","J2s","53s","Q6o","87o","74s","J7o","97o","Q7o","T7o","K3o","76o","T3s","Q5o","43s","63s","84s","65o","K2o","86o","94s","T2s","J6o","96o","Q4o","T6o","93s","52s","J5o","54o","92s","73s","75o","Q3o","42s","J4o","62s","83s","85o","64o","Q2o","82s","95o","32s","J3o","T5o","53o","T4o","72s","J2o","74o","T3o","43o","84o","63o","94o","T2o","52o","93o","73o","92o","42o","62o","83o","82o","32o","72o"};

string hands_pio = "AA,KK,QQ,JJ,TT,99,88,77,66,55,44,33,22,AK,AQ,AJ,AT,A9,A8,A7,A6,A5,A4,A3,A2,KQ,KJ,KT,K9,K8,K7,K6,K5,K4,K3,K2,QJ,QT,Q9,Q8,Q7,Q6,Q5,Q4,Q3,Q2,JT,J9,J8,J7,J6,J5,J4,J3,J2,T9,T8,T7,T6,T5,T4,T3,T2,98,97,96,95,94,93,92,87,86,85,84,83,82,76,75,74,73,72,65,64,63,62,54,53,52,43,42,32";
string hands_sp = "2d2h,2s2h,2c2h,3h2h,3d2h,3s2h,3c2h,4h2h,4d2h,4s2h,4c2h,5h2h,5d2h,5s2h,5c2h,6h2h,6d2h,6s2h,6c2h,7h2h,7d2h,7s2h,7c2h,8h2h,8d2h,8s2h,8c2h,9h2h,9d2h,9s2h,9c2h,Th2h,Td2h,Ts2h,Tc2h,Jh2h,Jd2h,Js2h,Jc2h,Qh2h,Qd2h,Qs2h,Qc2h,Kh2h,Kd2h,Ks2h,Kc2h,Ah2h,Ad2h,As2h,Ac2h,2s2d,2c2d,3h2d,3d2d,3s2d,3c2d,4h2d,4d2d,4s2d,4c2d,5h2d,5d2d,5s2d,5c2d,6h2d,6d2d,6s2d,6c2d,7h2d,7d2d,7s2d,7c2d,8h2d,8d2d,8s2d,8c2d,9h2d,9d2d,9s2d,9c2d,Th2d,Td2d,Ts2d,Tc2d,Jh2d,Jd2d,Js2d,Jc2d,Qh2d,Qd2d,Qs2d,Qc2d,Kh2d,Kd2d,Ks2d,Kc2d,Ah2d,Ad2d,As2d,Ac2d,2c2s,3h2s,3d2s,3s2s,3c2s,4h2s,4d2s,4s2s,4c2s,5h2s,5d2s,5s2s,5c2s,6h2s,6d2s,6s2s,6c2s,7h2s,7d2s,7s2s,7c2s,8h2s,8d2s,8s2s,8c2s,9h2s,9d2s,9s2s,9c2s,Th2s,Td2s,Ts2s,Tc2s,Jh2s,Jd2s,Js2s,Jc2s,Qh2s,Qd2s,Qs2s,Qc2s,Kh2s,Kd2s,Ks2s,Kc2s,Ah2s,Ad2s,As2s,Ac2s,3h2c,3d2c,3s2c,3c2c,4h2c,4d2c,4s2c,4c2c,5h2c,5d2c,5s2c,5c2c,6h2c,6d2c,6s2c,6c2c,7h2c,7d2c,7s2c,7c2c,8h2c,8d2c,8s2c,8c2c,9h2c,9d2c,9s2c,9c2c,Th2c,Td2c,Ts2c,Tc2c,Jh2c,Jd2c,Js2c,Jc2c,Qh2c,Qd2c,Qs2c,Qc2c,Kh2c,Kd2c,Ks2c,Kc2c,Ah2c,Ad2c,As2c,Ac2c,3d3h,3s3h,3c3h,4h3h,4d3h,4s3h,4c3h,5h3h,5d3h,5s3h,5c3h,6h3h,6d3h,6s3h,6c3h,7h3h,7d3h,7s3h,7c3h,8h3h,8d3h,8s3h,8c3h,9h3h,9d3h,9s3h,9c3h,Th3h,Td3h,Ts3h,Tc3h,Jh3h,Jd3h,Js3h,Jc3h,Qh3h,Qd3h,Qs3h,Qc3h,Kh3h,Kd3h,Ks3h,Kc3h,Ah3h,Ad3h,As3h,Ac3h,3s3d,3c3d,4h3d,4d3d,4s3d,4c3d,5h3d,5d3d,5s3d,5c3d,6h3d,6d3d,6s3d,6c3d,7h3d,7d3d,7s3d,7c3d,8h3d,8d3d,8s3d,8c3d,9h3d,9d3d,9s3d,9c3d,Th3d,Td3d,Ts3d,Tc3d,Jh3d,Jd3d,Js3d,Jc3d,Qh3d,Qd3d,Qs3d,Qc3d,Kh3d,Kd3d,Ks3d,Kc3d,Ah3d,Ad3d,As3d,Ac3d,3c3s,4h3s,4d3s,4s3s,4c3s,5h3s,5d3s,5s3s,5c3s,6h3s,6d3s,6s3s,6c3s,7h3s,7d3s,7s3s,7c3s,8h3s,8d3s,8s3s,8c3s,9h3s,9d3s,9s3s,9c3s,Th3s,Td3s,Ts3s,Tc3s,Jh3s,Jd3s,Js3s,Jc3s,Qh3s,Qd3s,Qs3s,Qc3s,Kh3s,Kd3s,Ks3s,Kc3s,Ah3s,Ad3s,As3s,Ac3s,4h3c,4d3c,4s3c,4c3c,5h3c,5d3c,5s3c,5c3c,6h3c,6d3c,6s3c,6c3c,7h3c,7d3c,7s3c,7c3c,8h3c,8d3c,8s3c,8c3c,9h3c,9d3c,9s3c,9c3c,Th3c,Td3c,Ts3c,Tc3c,Jh3c,Jd3c,Js3c,Jc3c,Qh3c,Qd3c,Qs3c,Qc3c,Kh3c,Kd3c,Ks3c,Kc3c,Ah3c,Ad3c,As3c,Ac3c,4d4h,4s4h,4c4h,5h4h,5d4h,5s4h,5c4h,6h4h,6d4h,6s4h,6c4h,7h4h,7d4h,7s4h,7c4h,8h4h,8d4h,8s4h,8c4h,9h4h,9d4h,9s4h,9c4h,Th4h,Td4h,Ts4h,Tc4h,Jh4h,Jd4h,Js4h,Jc4h,Qh4h,Qd4h,Qs4h,Qc4h,Kh4h,Kd4h,Ks4h,Kc4h,Ah4h,Ad4h,As4h,Ac4h,4s4d,4c4d,5h4d,5d4d,5s4d,5c4d,6h4d,6d4d,6s4d,6c4d,7h4d,7d4d,7s4d,7c4d,8h4d,8d4d,8s4d,8c4d,9h4d,9d4d,9s4d,9c4d,Th4d,Td4d,Ts4d,Tc4d,Jh4d,Jd4d,Js4d,Jc4d,Qh4d,Qd4d,Qs4d,Qc4d,Kh4d,Kd4d,Ks4d,Kc4d,Ah4d,Ad4d,As4d,Ac4d,4c4s,5h4s,5d4s,5s4s,5c4s,6h4s,6d4s,6s4s,6c4s,7h4s,7d4s,7s4s,7c4s,8h4s,8d4s,8s4s,8c4s,9h4s,9d4s,9s4s,9c4s,Th4s,Td4s,Ts4s,Tc4s,Jh4s,Jd4s,Js4s,Jc4s,Qh4s,Qd4s,Qs4s,Qc4s,Kh4s,Kd4s,Ks4s,Kc4s,Ah4s,Ad4s,As4s,Ac4s,5h4c,5d4c,5s4c,5c4c,6h4c,6d4c,6s4c,6c4c,7h4c,7d4c,7s4c,7c4c,8h4c,8d4c,8s4c,8c4c,9h4c,9d4c,9s4c,9c4c,Th4c,Td4c,Ts4c,Tc4c,Jh4c,Jd4c,Js4c,Jc4c,Qh4c,Qd4c,Qs4c,Qc4c,Kh4c,Kd4c,Ks4c,Kc4c,Ah4c,Ad4c,As4c,Ac4c,5d5h,5s5h,5c5h,6h5h,6d5h,6s5h,6c5h,7h5h,7d5h,7s5h,7c5h,8h5h,8d5h,8s5h,8c5h,9h5h,9d5h,9s5h,9c5h,Th5h,Td5h,Ts5h,Tc5h,Jh5h,Jd5h,Js5h,Jc5h,Qh5h,Qd5h,Qs5h,Qc5h,Kh5h,Kd5h,Ks5h,Kc5h,Ah5h,Ad5h,As5h,Ac5h,5s5d,5c5d,6h5d,6d5d,6s5d,6c5d,7h5d,7d5d,7s5d,7c5d,8h5d,8d5d,8s5d,8c5d,9h5d,9d5d,9s5d,9c5d,Th5d,Td5d,Ts5d,Tc5d,Jh5d,Jd5d,Js5d,Jc5d,Qh5d,Qd5d,Qs5d,Qc5d,Kh5d,Kd5d,Ks5d,Kc5d,Ah5d,Ad5d,As5d,Ac5d,5c5s,6h5s,6d5s,6s5s,6c5s,7h5s,7d5s,7s5s,7c5s,8h5s,8d5s,8s5s,8c5s,9h5s,9d5s,9s5s,9c5s,Th5s,Td5s,Ts5s,Tc5s,Jh5s,Jd5s,Js5s,Jc5s,Qh5s,Qd5s,Qs5s,Qc5s,Kh5s,Kd5s,Ks5s,Kc5s,Ah5s,Ad5s,As5s,Ac5s,6h5c,6d5c,6s5c,6c5c,7h5c,7d5c,7s5c,7c5c,8h5c,8d5c,8s5c,8c5c,9h5c,9d5c,9s5c,9c5c,Th5c,Td5c,Ts5c,Tc5c,Jh5c,Jd5c,Js5c,Jc5c,Qh5c,Qd5c,Qs5c,Qc5c,Kh5c,Kd5c,Ks5c,Kc5c,Ah5c,Ad5c,As5c,Ac5c,6d6h,6s6h,6c6h,7h6h,7d6h,7s6h,7c6h,8h6h,8d6h,8s6h,8c6h,9h6h,9d6h,9s6h,9c6h,Th6h,Td6h,Ts6h,Tc6h,Jh6h,Jd6h,Js6h,Jc6h,Qh6h,Qd6h,Qs6h,Qc6h,Kh6h,Kd6h,Ks6h,Kc6h,Ah6h,Ad6h,As6h,Ac6h,6s6d,6c6d,7h6d,7d6d,7s6d,7c6d,8h6d,8d6d,8s6d,8c6d,9h6d,9d6d,9s6d,9c6d,Th6d,Td6d,Ts6d,Tc6d,Jh6d,Jd6d,Js6d,Jc6d,Qh6d,Qd6d,Qs6d,Qc6d,Kh6d,Kd6d,Ks6d,Kc6d,Ah6d,Ad6d,As6d,Ac6d,6c6s,7h6s,7d6s,7s6s,7c6s,8h6s,8d6s,8s6s,8c6s,9h6s,9d6s,9s6s,9c6s,Th6s,Td6s,Ts6s,Tc6s,Jh6s,Jd6s,Js6s,Jc6s,Qh6s,Qd6s,Qs6s,Qc6s,Kh6s,Kd6s,Ks6s,Kc6s,Ah6s,Ad6s,As6s,Ac6s,7h6c,7d6c,7s6c,7c6c,8h6c,8d6c,8s6c,8c6c,9h6c,9d6c,9s6c,9c6c,Th6c,Td6c,Ts6c,Tc6c,Jh6c,Jd6c,Js6c,Jc6c,Qh6c,Qd6c,Qs6c,Qc6c,Kh6c,Kd6c,Ks6c,Kc6c,Ah6c,Ad6c,As6c,Ac6c,7d7h,7s7h,7c7h,8h7h,8d7h,8s7h,8c7h,9h7h,9d7h,9s7h,9c7h,Th7h,Td7h,Ts7h,Tc7h,Jh7h,Jd7h,Js7h,Jc7h,Qh7h,Qd7h,Qs7h,Qc7h,Kh7h,Kd7h,Ks7h,Kc7h,Ah7h,Ad7h,As7h,Ac7h,7s7d,7c7d,8h7d,8d7d,8s7d,8c7d,9h7d,9d7d,9s7d,9c7d,Th7d,Td7d,Ts7d,Tc7d,Jh7d,Jd7d,Js7d,Jc7d,Qh7d,Qd7d,Qs7d,Qc7d,Kh7d,Kd7d,Ks7d,Kc7d,Ah7d,Ad7d,As7d,Ac7d,7c7s,8h7s,8d7s,8s7s,8c7s,9h7s,9d7s,9s7s,9c7s,Th7s,Td7s,Ts7s,Tc7s,Jh7s,Jd7s,Js7s,Jc7s,Qh7s,Qd7s,Qs7s,Qc7s,Kh7s,Kd7s,Ks7s,Kc7s,Ah7s,Ad7s,As7s,Ac7s,8h7c,8d7c,8s7c,8c7c,9h7c,9d7c,9s7c,9c7c,Th7c,Td7c,Ts7c,Tc7c,Jh7c,Jd7c,Js7c,Jc7c,Qh7c,Qd7c,Qs7c,Qc7c,Kh7c,Kd7c,Ks7c,Kc7c,Ah7c,Ad7c,As7c,Ac7c,8d8h,8s8h,8c8h,9h8h,9d8h,9s8h,9c8h,Th8h,Td8h,Ts8h,Tc8h,Jh8h,Jd8h,Js8h,Jc8h,Qh8h,Qd8h,Qs8h,Qc8h,Kh8h,Kd8h,Ks8h,Kc8h,Ah8h,Ad8h,As8h,Ac8h,8s8d,8c8d,9h8d,9d8d,9s8d,9c8d,Th8d,Td8d,Ts8d,Tc8d,Jh8d,Jd8d,Js8d,Jc8d,Qh8d,Qd8d,Qs8d,Qc8d,Kh8d,Kd8d,Ks8d,Kc8d,Ah8d,Ad8d,As8d,Ac8d,8c8s,9h8s,9d8s,9s8s,9c8s,Th8s,Td8s,Ts8s,Tc8s,Jh8s,Jd8s,Js8s,Jc8s,Qh8s,Qd8s,Qs8s,Qc8s,Kh8s,Kd8s,Ks8s,Kc8s,Ah8s,Ad8s,As8s,Ac8s,9h8c,9d8c,9s8c,9c8c,Th8c,Td8c,Ts8c,Tc8c,Jh8c,Jd8c,Js8c,Jc8c,Qh8c,Qd8c,Qs8c,Qc8c,Kh8c,Kd8c,Ks8c,Kc8c,Ah8c,Ad8c,As8c,Ac8c,9d9h,9s9h,9c9h,Th9h,Td9h,Ts9h,Tc9h,Jh9h,Jd9h,Js9h,Jc9h,Qh9h,Qd9h,Qs9h,Qc9h,Kh9h,Kd9h,Ks9h,Kc9h,Ah9h,Ad9h,As9h,Ac9h,9s9d,9c9d,Th9d,Td9d,Ts9d,Tc9d,Jh9d,Jd9d,Js9d,Jc9d,Qh9d,Qd9d,Qs9d,Qc9d,Kh9d,Kd9d,Ks9d,Kc9d,Ah9d,Ad9d,As9d,Ac9d,9c9s,Th9s,Td9s,Ts9s,Tc9s,Jh9s,Jd9s,Js9s,Jc9s,Qh9s,Qd9s,Qs9s,Qc9s,Kh9s,Kd9s,Ks9s,Kc9s,Ah9s,Ad9s,As9s,Ac9s,Th9c,Td9c,Ts9c,Tc9c,Jh9c,Jd9c,Js9c,Jc9c,Qh9c,Qd9c,Qs9c,Qc9c,Kh9c,Kd9c,Ks9c,Kc9c,Ah9c,Ad9c,As9c,Ac9c,TdTh,TsTh,TcTh,JhTh,JdTh,JsTh,JcTh,QhTh,QdTh,QsTh,QcTh,KhTh,KdTh,KsTh,KcTh,AhTh,AdTh,AsTh,AcTh,TsTd,TcTd,JhTd,JdTd,JsTd,JcTd,QhTd,QdTd,QsTd,QcTd,KhTd,KdTd,KsTd,KcTd,AhTd,AdTd,AsTd,AcTd,TcTs,JhTs,JdTs,JsTs,JcTs,QhTs,QdTs,QsTs,QcTs,KhTs,KdTs,KsTs,KcTs,AhTs,AdTs,AsTs,AcTs,JhTc,JdTc,JsTc,JcTc,QhTc,QdTc,QsTc,QcTc,KhTc,KdTc,KsTc,KcTc,AhTc,AdTc,AsTc,AcTc,JdJh,JsJh,JcJh,QhJh,QdJh,QsJh,QcJh,KhJh,KdJh,KsJh,KcJh,AhJh,AdJh,AsJh,AcJh,JsJd,JcJd,QhJd,QdJd,QsJd,QcJd,KhJd,KdJd,KsJd,KcJd,AhJd,AdJd,AsJd,AcJd,JcJs,QhJs,QdJs,QsJs,QcJs,KhJs,KdJs,KsJs,KcJs,AhJs,AdJs,AsJs,AcJs,QhJc,QdJc,QsJc,QcJc,KhJc,KdJc,KsJc,KcJc,AhJc,AdJc,AsJc,AcJc,QdQh,QsQh,QcQh,KhQh,KdQh,KsQh,KcQh,AhQh,AdQh,AsQh,AcQh,QsQd,QcQd,KhQd,KdQd,KsQd,KcQd,AhQd,AdQd,AsQd,AcQd,QcQs,KhQs,KdQs,KsQs,KcQs,AhQs,AdQs,AsQs,AcQs,KhQc,KdQc,KsQc,KcQc,AhQc,AdQc,AsQc,AcQc,KdKh,KsKh,KcKh,AhKh,AdKh,AsKh,AcKh,KsKd,KcKd,AhKd,AdKd,AsKd,AcKd,KcKs,AhKs,AdKs,AsKs,AcKs,AhKc,AdKc,AsKc,AcKc,AdAh,AsAh,AcAh,AsAd,AcAd,AcAs";


string compress(string ss)
{	
	const char *src = ss.c_str();
	char dst[4];
	memset(dst, 0, sizeof(dst));

	dst[0] = src[0];
	dst[1] = src[2];
	if (src[0]!=src[2])
		dst[2] = (src[1] == src[3]) ? 's' : 'o';

	return dst;
}


string parse_file(string filename)
{
	int i;
	ifstream file(filename);
	string str;

	auto hands_pio_list = split(hands_pio, ",");
	auto hands_sp_list = split(hands_sp, ",");

	map<string, vector<string> > pio_to_sp_dict;

	for (auto s1 : hands_pio_list) {
		vector<string> v;
		pio_to_sp_dict.emplace(s1, v);
	}

	for (auto s2: hands_sp_list){
		auto key = compress(s2);
		pio_to_sp_dict[key].push_back(s2);
	}

	string out;
	char buf[1024];
	
	while (getline(file,str)){
		auto v = split(str,",");
		std::vector<pair<float, string>> vec;

		// parse all hands into a vector and sort them ascending
		for (auto x:v){
			auto v2 = split(x,":");
			string key;
			float v;
			if (v2.size() == 2){ key = v2[0]; v = stod(v2[1]) * 100.0f;}
			else if (v2.size()==1) { key = v2[0]; v = 100.0f; }
			else continue;

			if (pio_to_sp_dict.find(key) != pio_to_sp_dict.end()) 
				vec.push_back({v, key});
			if (pio_to_sp_dict.find(key+'s') != pio_to_sp_dict.end())
				vec.push_back({v, key+'s' });
			if (pio_to_sp_dict.find(key+'o') != pio_to_sp_dict.end())
				vec.push_back({v, key+'o' });
		}
		if (vec.size() == 0) continue;

		// prepare output string
		std::stable_sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a.first < b.first; });

		float last=-1;
		for (auto it : vec) {
			float v = it.first;
			auto key = it.second;
			if (v != last) {
				if (last >= 0) { sprintf(buf, "[/%.2f], ", last); out += buf; }
				sprintf(buf, "[%.2f]", v); out += buf;
				last = v;
			} else 
				out += ", ";

			for (i = 0; i < pio_to_sp_dict[key].size(); i++) {
				if (i > 0) out += ", ";
				out += pio_to_sp_dict[key][i];
			}
		}
		if (last >= 0) { sprintf(buf, "[/%.2f]", last);  out += buf; }
	}

	//cout << "---\n" << out << endl;

	//FILE* fp = fopen("test.txt", "wt");
	//fprintf(fp, "%s\n", out.c_str());
	//fclose(fp);

	//return 1;
	return out;
}
