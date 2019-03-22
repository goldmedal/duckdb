//===----------------------------------------------------------------------===//
//                         DuckDB
//
// planner/bound_query_node.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "parser/query_node.hpp"
#include "planner/expression.hpp"

namespace duckdb {

struct BoundOrderByNode {
	BoundOrderByNode() {
	}
	BoundOrderByNode(OrderType type, unique_ptr<Expression> expression) : type(type), expression(move(expression)) {
	}

	OrderType type;
	unique_ptr<Expression> expression;
};

//! Bound equivalent of QueryNode
class BoundQueryNode {
public:
	BoundQueryNode(QueryNodeType type) : type(type) {
	}
	virtual ~BoundQueryNode() {
	}

	//! The type of the query node, either SetOperation or Select
	QueryNodeType type;
	//! DISTINCT or not
	bool select_distinct = false;
	//! List of order nodes
	vector<BoundOrderByNode> orders;
	//! LIMIT count
	int64_t limit = -1;
	//! OFFSET
	int64_t offset = -1;

	//! The types returned by this QueryNode.
	vector<SQLType> types;

	virtual const vector<unique_ptr<Expression>> &GetSelectList() const = 0;
};

}; // namespace duckdb
