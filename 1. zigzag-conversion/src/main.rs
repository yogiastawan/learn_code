fn main() {
    let re = Solution::convert("PAYPALISHIRING".to_string(), 3);
    assert_eq!(&re, "PAHNAPLSIIGYIR");
    let re = Solution::convert("PAYPALISHIRING".to_string(), 4);
    assert_eq!(&re, "PINALSIGYAHRPI");
}

struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            println!("num rows: 1=>{}", &s);
            return s;
        }
        let mut zz: Vec<char> = Vec::with_capacity(s.len());

        for i in 0..num_rows {
            let mut pos = i;
            let mut adder = if i == num_rows - 1 {
                (num_rows - 1) * 2
            } else {
                (num_rows - i - 1) * 2
            };

            println!("row: {}|| adder:{}", pos, adder);
            let mut toggle=true;
            while pos < s.len() as i32 {
                let c = s.chars().nth(pos as usize).unwrap();
                println!("\tpos:{}=>{}", pos, c);
                zz.push(c);
                pos += adder;

                if i>0&&i<num_rows-1{
                    adder=if toggle {
                        i*2
                    }else{
                        (num_rows - i - 1) * 2
                    };
                    toggle=!toggle;
                }
            }
        }
        String::from_iter(zz.iter())
    }
}
