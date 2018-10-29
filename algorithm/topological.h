#pragma once
#include"digraph.h"
#include"edge_weighted_digraph.h"
#include"directed_cycle.h"
#include"edge_weighted_directed_cycle.h"
#include"depth_first_order.h"
#include"stack.h"
#include<vector>

namespace algorithmcpp {
	class Topological {
	private:
		std::vector<size_t> vertex_rank_;
		Stack<size_t> vertex_order_;

	public:
		Topological() = delete;
		Topological(const Topological&) = default;
		Topological(Topological &&) noexcept = default;
		Topological &operator=(const Topological &) = default;
		Topological &operator=(Topological &&) noexcept = default;
		~Topological() = default;

		Topological(const Digraph &G) :vertex_rank_(std::vector<size_t>(G.V())){
			DirectedCycle finder(G);
			if (!finder.HasCycle()) {
				DepthFirstOrder dfs(G);
				vertex_order_ = dfs.ReversePost();
				size_t i = 0;
				for (size_t v : vertex_order_) {
					vertex_rank_[v] = i++;
				}
			}
		}

		Topological(const EdgeWeightedDigraph &G) :vertex_rank_(std::vector<size_t>(G.V())) {
			EdgeWeightedDirectedCycle finder(G);
			if (!finder.HasCycle()) {
				DepthFirstOrder dfs(G);
				vertex_order_ = dfs.ReversePost();
				size_t i = 0;
				for (size_t v : vertex_order_) {
					vertex_rank_[v] = i++;
				}
			}
		}

	private:
		void ValidateVertex(size_t v) const {
			size_t V = vertex_rank_.size();
			if (v >= V) throw std::invalid_argument("vertex " + std::to_string(v) + " is not between 0 and " + std::to_string(V - 1));
		}

	public:
		Stack<size_t> Order() const {
			return vertex_order_;
		}

		bool HasOrder() const {
			return !vertex_order_.IsEmpty();
		}

		int Rank(size_t v) const {
			ValidateVertex(v);
			if (HasOrder()) return static_cast<int>(vertex_rank_[v]);
			else return -1;
		}

		static void MainTest(int argc = 0, char *argv[] = nullptr) {
			std::string filename("");
			std::string delimiter("");
			//SymbolDigraph
		}
	};
}