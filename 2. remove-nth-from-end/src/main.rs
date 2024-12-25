fn main() {
    let mut head = ListNode::new(1);
    let mut l2 = ListNode::new(2);
    let mut l3 = ListNode::new(3);
    let mut l4 = ListNode::new(4);
    let l5 = ListNode::new(5);
    l4.next = Some(Box::new(l5));
    l3.next = Some(Box::new(l4));
    l2.next = Some(Box::new(l3));
    head.next = Some(Box::new(l2));

    println!("before: {:?}", &head);

    let a = Solution::remove_nth_from_end(Some(Box::new(head)), 1);
    println!("after: {:?}", &a);
}

struct Solution;

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        dummy.next = head.clone();
        let mut dummy = Some(Box::new(dummy));
        let mut left = dummy.as_mut();
        let mut right = head.as_ref();

        for _ in 0..n {
            if right.is_none() {
                break;
            }
            right = right.unwrap().next.as_ref();
        }

        while right.is_some() {
            left = left.unwrap().next.as_mut();
            right = right.unwrap().next.as_ref();
        }

        // let l = left.unwrap().next.take();
        left.unwrap().next = left.as_mut().unwrap().next.as_mut().unwrap().next.take();
        dummy.unwrap().next
    }
}

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}
