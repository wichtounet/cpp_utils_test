node {
   try {
       stage 'git'
       checkout([$class: 'GitSCM', branches: [[name: '*/master']], doGenerateSubmoduleConfigurations: false, extensions: [[$class: 'SubmoduleOption', disableSubmodules: false, recursiveSubmodules: true, reference: '', trackingSubmodules: false]], submoduleCfg: [], userRemoteConfigs: [[url: 'https://github.com/wichtounet/cpp_utils_test.git']]])

       stage 'pre-analysis'
       sh 'cppcheck --xml-version=2 --enable=all --std=c++11 include/cpp_utils/*.hpp test/*.cpp 2> cppcheck_report.xml'
       sh 'sloccount --duplicates --wide --details include/cpp_utils/*.hpp test/*.cpp > sloccount.sc'
       sh 'cccc include/cpp_utils/*.hpp test/*.cpp test_compile/*.cpp || true'

       env.CXX="g++-4.9.4"
       env.LD="g++-4.9.4"

       stage 'build'
       sh 'make clean'
       sh 'make -j6 all'

       stage 'test'
       sh './debug/bin/test -r junit -d yes -o catch_report.xml || true'
       sh 'gcovr -x -b -r . --object-directory=release_debug/test > coverage_report.xml'
       archive 'catch_report.xml'

       stage 'sonar'
       sh '/opt/sonar-runner/bin/sonar-runner'
       currentBuild.result = 'SUCCESS'
   } catch (any) {
       currentBuild.result = 'FAILURE'
       throw any
   } finally {
       step([$class: 'Mailer',
           notifyEveryUnstableBuild: true,
           recipients: "baptiste.wicht@gmail.com",
           sendToIndividuals: true])
   }
}
