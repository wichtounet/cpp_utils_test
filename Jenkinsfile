pipeline {
    agent any

    environment {
       CXX = "g++-4.9.4"
       LD = "g++-4.9.4"
    }

    stages {
        stage ('git'){
            steps {
                checkout([
                    $class: 'GitSCM',
                    branches: scm.branches,
                    doGenerateSubmoduleConfigurations: false,
                    extensions: scm.extensions + [[$class: 'SubmoduleOption', disableSubmodules: false, recursiveSubmodules: true, reference: '', trackingSubmodules: false]],
                    submoduleCfg: [],
                    userRemoteConfigs: scm.userRemoteConfigs])
            }
        }

        stage ('pre-analysis') {
            steps {
                sh 'cppcheck --xml-version=2 --enable=all --std=c++11 include/cpp_utils/*.hpp test/src/*.cpp 2> cppcheck_report.xml'
                sh 'sloccount --duplicates --wide --details include/cpp_utils/*.hpp test/src/*.cpp > sloccount.sc'
                sh 'cccc include/cpp_utils/*.hpp test/*.cpp || true'
            }
        }

        stage ('build'){
            steps {
                sh 'make clean'
                sh 'make -j6 all'
            }
        }

        stage ('test'){
            steps {
                sh './debug/bin/test -r junit -d yes -o catch_report.xml || true'
                sh 'gcovr -x -b -r . --object-directory=release_debug/test > coverage_report.xml'
                archive 'catch_report.xml'
                junit 'catch_report.xml'
            }
        }

        stage ('sonar-master'){
            when {
                branch 'master'
            }
            steps {
                sh "/opt/sonar-runner/bin/sonar-runner"
            }
        }

        stage ('sonar-branch'){
            when {
                not {
                    branch 'master'
                }
            }
            steps {
                sh "/opt/sonar-runner/bin/sonar-runner -Dsonar.branch=${env.BRANCH_NAME}"
            }
        }
    }

    post {
        always {
            step([$class: 'Mailer',
                notifyEveryUnstableBuild: true,
                recipients: "baptiste.wicht@gmail.com",
                sendToIndividuals: true])
        }
    }
}
