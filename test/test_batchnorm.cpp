//
// Created by fss on 22-11-30.
//
#include <gtest/gtest.h>
#include <glog/logging.h>
#include "parser/runtime_ir.hpp"
#include "data/load_data.hpp"

TEST(test_layer, forward_batchnorm) {
  using namespace kuiper_infer;
  RuntimeGraph graph
      ("tmp/batchnorm/resnet_batchnorm.pnnx.param",
       "tmp/batchnorm/resnet_batchnorm.pnnx.bin");

  graph.Build("pnnx_input_0", "pnnx_output_0");

  std::shared_ptr<Tensor<float>> input1 = std::make_shared<Tensor<float>>(3, 128, 128);
  input1->Fill(1.);

  std::shared_ptr<Tensor<float>> input2 = std::make_shared<Tensor<float>>(3, 128, 128);
  input2->Fill(1.);

  std::shared_ptr<Tensor<float>> input3 = std::make_shared<Tensor<float>>(3, 128, 128);
  input3->Fill(1.);

  std::shared_ptr<Tensor<float>> input4 = std::make_shared<Tensor<float>>(3, 128, 128);
  input4->Fill(1.);

  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input1);
  inputs.push_back(input2);
  inputs.push_back(input3);
  inputs.push_back(input4);

  std::vector<std::shared_ptr<Tensor<float>>> output_tensors = graph.Forward(inputs, false);
  ASSERT_EQ(output_tensors.size(), 4);

  const auto &output1 = output_tensors.at(0)->at(0);
  const auto &output2 = CSVDataLoader::LoadData("tmp/batchnorm/1.csv");
  ASSERT_EQ(output1.size(), output2.size());

  const uint32_t size = output1.size();
  for (uint32_t i = 0; i < size; ++i) {
    ASSERT_LE(abs(output1.at(i) - output2.at(i)), 1e-6);
  }
}


TEST(test_layer, forward_batchnorm2) {
  using namespace kuiper_infer;
  RuntimeGraph graph
      ("tmp/batchnorm/resnet_batchnorm2.pnnx.param",
       "tmp/batchnorm/resnet_batchnorm2.pnnx.bin");

  graph.Build("pnnx_input_0", "pnnx_output_0");

  std::shared_ptr<Tensor<float>> input1 = std::make_shared<Tensor<float>>(3, 128, 128);
  input1->Fill(1.);

  std::shared_ptr<Tensor<float>> input2 = std::make_shared<Tensor<float>>(3, 128, 128);
  input2->Fill(1.);

  std::shared_ptr<Tensor<float>> input3 = std::make_shared<Tensor<float>>(3, 128, 128);
  input3->Fill(1.);

  std::shared_ptr<Tensor<float>> input4 = std::make_shared<Tensor<float>>(3, 128, 128);
  input4->Fill(1.);

  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input1);
  inputs.push_back(input2);
  inputs.push_back(input3);
  inputs.push_back(input4);

  std::vector<std::shared_ptr<Tensor<float>>> output_tensors = graph.Forward(inputs, false);
  ASSERT_EQ(output_tensors.size(), 4);

  const auto &output1 = output_tensors.at(0)->at(0);
  const auto &output2 = CSVDataLoader::LoadData("tmp/batchnorm/2.csv");
  ASSERT_EQ(output1.size(), output2.size());

  const uint32_t size = output1.size();
  for (uint32_t i = 0; i < size; ++i) {
    ASSERT_LE(abs(output1.at(i) - output2.at(i)), 1e-6);
  }


  const auto &output3 = output_tensors.at(0)->at(63);
  const auto &output4 = CSVDataLoader::LoadData("tmp/batchnorm/3.csv");
  ASSERT_EQ(output1.size(), output2.size());

  const uint32_t size2 = output3.size();
  for (uint32_t i = 0; i < size2; ++i) {
    ASSERT_LE(abs(output3.at(i) - output4.at(i)), 1e-6);
  }
}